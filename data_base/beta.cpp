#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>
#include <string>

#include <stdlib.h>
#include <windows.h>
#include <shlwapi.h>

using namespace std;

string ExePath()
{
    return ("C://Users//egrvr//Documents//proga//c_inf//data_base//");
}

void display(int *link_table, int SizeOf, string **array2d, int count, string *names, int *indexing)
{
    cout << '\n';
    for (int y = 0; y < SizeOf; y++)
        cout << names[y + 1] << '\t';
    cout << '\n';
    int p = 0;
    for (int x = 0; x < count; x++)
    {
        if (x != indexing[p])
            continue;
        else
            p++;
        for (int y = 0; y < SizeOf; y++)
            cout << array2d[y][link_table[x * SizeOf + y]] << '\t';
        cout << '\n';
    }
}

string *element_add(string *a, string el)
{

    auto b = new string[(sizeof(a) / sizeof(*a)) + 1];
    copy(a, a + (sizeof(a) / sizeof(*a)), b);
    b[sizeof(a) / sizeof(*a)] = el;
    delete[] a;
    return b;
}

int *element_add(int *a, int *el)
{
    auto b = new int[(sizeof(a) / sizeof(*a)) + (sizeof(el) / sizeof(*el))];
    copy(a, a + (sizeof(a) / sizeof(*a)), b);
    copy(el, el + (sizeof(el) / sizeof(*el)), b + (sizeof(a) / sizeof(*a)));
    return b;
}

int *add(int *link_table, int SizeOf, string **array2d, int count, string *names)
{
    auto temp = new int[SizeOf];
    for (int i = 0; i < SizeOf; i++)
    {
        cout << "\n\twaitig for entering " + names[i + 1] + " : ";
        string input_str;
        cin >> input_str;
        int index = std::distance(array2d[i], std::find(array2d[i], array2d[i] + sizeof(array2d[i]) / sizeof(array2d[i][0]) + 1, input_str));
        if (index == sizeof(array2d[i]) / sizeof(array2d[i][0]) + 1)
        {

            array2d[i] = element_add(array2d[i], input_str);
        }
        temp[i] = index;
    }
    auto res = element_add(link_table, temp);
    delete[] temp;
    return res;
}

void search(int *link_table, int SizeOf, string **array2d, int count, string *names)
{
    cout << "\n\twaitig for search param: ";
    string input_str;
    cin >> input_str;
    // input_str = "numbers";
    int x = std::distance(names, std::find(names + 1, names + SizeOf + 1, input_str)) - 1;
    if (x == SizeOf)
    {
        cout << "\n\tNo such value! \n\tExting...";
        return;
    }
    cout << "\n\twaitig for value: ";
    cin >> input_str;
    int index = std::distance(array2d[x], std::find(array2d[x], array2d[x] + sizeof(array2d[x]) / sizeof(array2d[x][0]) + 1, input_str));
    if (index == sizeof(array2d[x]) / sizeof(array2d[x][0]) + 1)
    {
        cout << "\n\tNo such value! \n\tExting...";
        return;
    }

    auto search_result = new int[count];
    int j = 0;
    cout << "\n\tFound index: ";
    for (int i = 0; i < count; i++)
    {
        if (link_table[i * SizeOf + x] == index)
        {
            search_result[j++] = i;
            cout << i << "; ";
        }
    }
}

void input(int *link_table, int SizeOf, string **array2d, int count, string *names)
{
    /*
    0 - exit
    1 - search
    2 - delete
    3 - edit
    4 - add
    5 - display
    */
    auto A = new int[count];
    for (int i = 0; i < count; i++)
    {
        A[i] = i;
    }

    cout << "\n0 - exit \n1 - search \n2 - delete \n3 - edit \n4 - add \n5 - display\n";

    int input_n;

    while (true)
    {
        cin >> input_n;

        switch (input_n)
        {
        case (0):
            exit;
            break;
        case (1):
            search(link_table, SizeOf, array2d, count, names);
            break;
        case (4):
            link_table = add(link_table, SizeOf, array2d, count, names);
            break;
        case (5):
            display(link_table, SizeOf, array2d, count, names, A);
            break;
        default:
            break;
        }
    }

    input(link_table, SizeOf, array2d, count, names);
}

int *readDataLinks(int SizeOf, string name)
{
    string filename(ExePath() + name + ".txt");
    int number;

    ifstream input_file(filename);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    }
    int i = 0;

    input_file >> number;
    auto array_to_write = new int[SizeOf * number + 1];
    array_to_write[i++] = number;
    while (input_file >> number)
    {
        array_to_write[i++] = number;
    }
    cout << endl;
    input_file.close();
    return array_to_write;
}

string *readData(string name)
{
    string filename(ExePath() + name + ".txt");
    string line;

    ifstream input_file(filename);

    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    }
    int i = 0;
    int number;
    input_file >> number;
    auto array_to_write = new string[number];
    getline(input_file, line);

    while (getline(input_file, line))
    {
        array_to_write[i++] = line;
    }

    input_file.close();
    return array_to_write;
}

void Start_Session()
{
    int params = 3;
    auto lengthes = new int[params];

    int count;
    string name;
    {
        name = "database";
        auto temp = readData(name);
        count = stoi(temp[0]);
        name = temp[1];
    }
    auto names = readData(name);

    auto array2d = new string *[count - 1];

    for (auto i = 1; i < count; i++)
    {
        array2d[i - 1] = readData(names[i]);
    }

    auto link_tables = readDataLinks(count - 1, names[0]);
    auto size_links = link_tables[0];
    auto link_table = &(link_tables[1]);
    cout << "start session with data base \n";

    input(link_table, count - 1, array2d, size_links, names);
    cout << "\n exit";
}

int main(int args, char **argv)
{

    Start_Session();
    std::cout << '\n'
              << "End" << '\n';
    system("pause");
    return 0;
}