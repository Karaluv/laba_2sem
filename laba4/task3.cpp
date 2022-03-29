#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>

using namespace std;


void show_binary_V1(float number)
{

union fp_bit_twiddler {
    float f;
    int i;
} q;
q.f = number;

unsigned long int mask = 1<< 31; 
cout << ((mask & (q.i))>>31);
for (char i = 0; i<31; i++)
cout << ((mask & (q.i = q.i << 1))>>31);
cout << '\n';
}



int main(int args, char **argv)
{

    float number;
    cin >> number;

    show_binary_V1(number);

    std::cout << '\n'
              << "End" << '\n';
    system("pause");
    return 0;
}