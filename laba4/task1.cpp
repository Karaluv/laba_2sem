#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>

using namespace std;

void show_binary_reverse(unsigned int number)
{
    unsigned int mask = 1;
    cout << (mask & (number));
    for (char i = 0; i < 31; i++)
        cout << (mask & (number = number >> 1));
    cout << '\n';
}

void show_binary_V1(unsigned int number)
{
    unsigned int mask = 1 << 31;
    cout << ((mask & (number)) >> 31);
    for (char i = 0; i < 31; i++)
        cout << ((mask & (number = number << 1)) >> 31);
    cout << '\n';
}

int main(int args, char **argv)
{

    unsigned int number;
    cin >> number;
    show_binary_V1(number);
    show_binary_reverse(number);

    std::cout << '\n'
              << "End" << '\n';
    system("pause");
    return 0;
}