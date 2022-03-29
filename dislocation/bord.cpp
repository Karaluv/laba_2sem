#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>

using namespace std;

int random_way()
{

    static mt19937_64 engine(random_device{}());
    static uniform_int_distribution<int> uni(0, 3);
    return uni(engine);
}

int random_generate(int chance = 0, bool changed = false)
{
    static mt19937_64 engine(random_device{}());
    static uniform_int_distribution<int> uni(0, chance);
    if (changed)
        uni.param(uniform_int_distribution<int>::param_type(0, chance));
    int c = uni(engine);
    return uni(engine);
}

void print_out(char field[], int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        cout << '\n';
        for (int x = 0; x < width; x++)
            cout << (int)field[y * width + x] << '\t';
    }
    cout << '\n';
}
void initial_condition(char field[], int width, int height, int chance)
{
    int way;
    way = random_generate(chance, true);
    for (unsigned int y = 0; y < height; y++)
        for (unsigned int x = 0; x < width; x++)
        {
            field[y * width + x] = 0;

            way = random_generate();
            if (way == 0)
                field[y * width + x] = 1;
            if (x == 0)
                field[y * width + x] = 0;
            if (y == 0)
                field[y * width + x] = 0;
            if (x == width - 1)
                field[y * width + x] = 0;
            if (y == height - 1)
                field[y * width + x] = 0;
        }
    // field[(height / 2) * width + width / 2] = 1;
    // field[(random_generate(998)+1)*width + (random_generate(998)+1)] = 1;
}
int boundary_condition(int position, int width_v = 5, int height_v = 5)
{
    static int width;
    static int height;

    if (position == -1)
    {
        width = width_v;
        height = height_v;
        return 0;
    }

    if (position < width)
        position += width * (height - 2);
    if (position > width * (height - 1))
        position += -width * (height - 2);

    if (position % width == 0)
        position += width - 2;
    if (position % width == width - 1)
        position += -(width - 2);

    return position;
}

void fix_blocks(char field[], unsigned int positions[], int width, int height, int n)
{
    int position;
    int way;
    bool go = false;
    int new_location;

    for (int i = 0; i < n; i++)
    {
        if (positions[i] == 0)
            continue;
        position = positions[i];

        if (field[position] > 1)
            while (!go)
            {
                way = random_way();
                if (field[boundary_condition(((way == 0) - (way == 1)) * width + (way == 3) - (way == 2) + position)] == -1)
                {
                    field[position]--;
                    field[boundary_condition(((way == 0) - (way == 1)) * width + (way == 3) - (way == 2) + position)] = 1;
                    positions[i] = boundary_condition(((way == 0) - (way == 1)) * width + (way == 3) - (way == 2) + position);
                    go = true;
                }
            }
        go = false;
    }
}

void move_blocks(char field[], unsigned int positions[], int width, int height, int n)
{

    int way;
    int position;

    for (int i = 0; i < n; i++)
    {
        if (positions[i] == 0)
            continue;
        position = positions[i];
        field[position] = -1;
        way = random_way();
        positions[i] = ((way == 0) - (way == 1)) * width + (way == 3) - (way == 2) + position;

        positions[i] = boundary_condition(positions[i]);

        field[positions[i]] += 1;
    }
}

int check_active(char field[], unsigned int positions[], int width, int height, int n)
{
    int position;

    for (int i = 0; i < n; i++)
    {
        if (positions[i] == 0)
            continue;

        position = positions[i];

        if ((field[boundary_condition(position + 1)] > 0) || (field[boundary_condition(position - 1)] > 0) || (field[boundary_condition(position + width)] > 0) || (field[boundary_condition(position - width)] > 0))
        {
            field[position] = -9;
            positions[i] = 0;
        }
        else if ((field[boundary_condition(position + 1)] + field[boundary_condition(position - 1)] + field[boundary_condition(position + width)] + field[boundary_condition(position - width)]) < -4)
        {
            field[position] = -9;
            positions[i] = 0;
        }
        else
        {
            field[boundary_condition(position + 1)] = 0;
            field[boundary_condition(position - 1)] = 0;
            field[boundary_condition(position + width)] = 0;
            field[boundary_condition(position - width)] = 0;
        }
    }

    return n;
}

void iteration(char field[], unsigned int positions[], int width, int height, int n)
{

    print_out(field, width, height);

    n = check_active(field, positions, width, height, n);
    print_out(field, width, height);
    move_blocks(field, positions, width, height, n);
    print_out(field, width, height);

    fix_blocks(field, positions, width, height, n);
}

void save_and_print(char field[], int width, int height, int time, int chance)
{
    static ofstream myfile;
    myfile.open("C://Users//egrvr//Documents//jog1.csv", ofstream::app);
    myfile << width << ';' << height << ';' << chance << ';' << time << '\n';
    myfile.close();
}

void run_all(unsigned int positions[], char field[], int width, int height, int chance)
{
    initial_condition(field, width, height, chance);
    boundary_condition(-1, width, height);
    int time;
    bool found = false;

    int n = 0;
    int position;
    for (unsigned int y = 1; y < height - 1; y++)
    {
        for (unsigned int x = 1; x < width - 1; x++)
        {
            position = y * width + x;
            if (field[y * width + x] == 1)
            {
                positions[n] = position;
                n++;
            }
        }
        if (found)
            break;
    }

    for (time = 0; time <= 4000000; time++)
    {
        iteration(field, positions, width, height, n);

        for (int i = 0; i < n; i++)
            if (positions[i] != 0)
                found = true;

        if (!found)
            break;

        found = false;
    }

    save_and_print(field, width, height, time, chance);
}

int main(int args, char **argv)
{
    char field[1000000];
    unsigned int positions[200000];

    int number_of_iterations = 1;
    int max_size = 6;
    int min_size = 6;
    int max_chance = 6;
    int min_chance = 6;

    int step_chance = 1;
    boundary_condition(-1, 5, 5);
    assert(boundary_condition(5) == 8);
    assert(boundary_condition(9) == 6);
    assert(boundary_condition(2) == 17);
    assert(boundary_condition(22) == 7);
    assert(boundary_condition(13) == 13);
    // assert(boundary_condition(5,4,4) == 7);

    ofstream myfile;
    myfile.open("C://Users//egrvr//Documents//jog1.csv", ofstream::out | ofstream::trunc);
    myfile.close();
    cout << max_chance << ' ' << min_chance << ' ' << step_chance << '\n';
    for (int n = 1; n <= number_of_iterations; n++)
    {
        cout << n << ' ';
        for (int size = min_size; size <= max_size; size++)
            for (int chance = min_chance; chance <= max_chance; chance += step_chance)
                run_all(positions, field, size, size, chance);
    }

    std::cout << '\n'
              << "End" << '\n';
    // system("pause");
    return 0;
}