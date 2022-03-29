#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>

using namespace std;

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

void generate_array(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = (rand());
    }
}

bool check_dist(int x1, int y1, int x2, int y2, int r2)
{
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < r2);
}

int *GetAllParcticles_inR(int particles[], int index, int number_of_particles, int r2)
{
    int x0 = particles[2 * index];
    int y0 = particles[2 * index + 1];

    int length = 0;

    int *neibor = new int[number_of_particles];

    for (int i = 0; i < number_of_particles; i++)
    {
        if (check_dist(x0, y0, particles[2 * i], particles[2 * i + 1], r2) * (i != index))
        {
            neibor[length] = i;
            length++;
        }
    }

    int *neibors = new int[length + 1];

    neibors[0] = length;
    for (int i = 0; i < length; i++)
        neibors[i + 1] = neibor[i];

    delete[] neibor;

    return neibors;
}

void save_and_print(char field[], int width, int height, int time, int chance)
{
    static ofstream myfile;
    myfile.open("C://Users//egrvr//Documents//jog1.csv", ofstream::app);
    myfile << width << ';' << height << ';' << chance << ';' << time << '\n';
    myfile.close();
}

void run_it(int *particles, int **neibors, int *neibors_num, int r, int number_of_particles)
{
    int r2 = r * r;

    for (int i = 0; i < number_of_particles; i++)
    {
        int *res = GetAllParcticles_inR(particles, i, number_of_particles, r2);
        neibors_num[i] = res[0];
        neibors[i] = &res[1];
        for (int j = 0; j < neibors_num[i]; j++)
        {
            cout << neibors[i][j] << '\t';
        }
        cout << '\n';
    }

    // save_and_print(field, width, height, time, chance);
}

bool check()
{
    int number_of_particles = 5;
    // int *particles = new int[number_of_particles];
    int particles[] = {4, 0, 5, 0, 6, 0, 40, 0, 41, 0};
    int **neibors = new int *[number_of_particles];
    int *neibors_num = new int[number_of_particles];

    int r = 2;

    int tester[] = {1,0,2,1,4,3};

    run_it(particles, neibors, neibors_num, r, number_of_particles);

    int k =0;

    for (int i = 0; i < number_of_particles; i++)
    {
        for (int j = 0; j < neibors_num[i]; j++)
        {
            if (neibors[i][j] != tester[k])
            {
            cout << "error";
            return false;
            }
            k++;
        }
    }

    delete[] neibors_num;
    delete[] particles;
    for (int i = 0; i < number_of_particles; i++)
        delete[] neibors[i];
    delete[] neibors;
    return true;
}



int main(int args, char **argv)
{
    assert(check()==true);
    //test();

    std::cout << '\n'
              << "End" << '\n';
    // system("pause");
    return 0;
}