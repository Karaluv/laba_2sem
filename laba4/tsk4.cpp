#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>

using namespace std;




int main(int args, char **argv)
{
cout << fixed;
cout.precision(2);

    float n = 1;
    for (int i = 0; i<10000;i++)
        cout << (n=n*10)<<'\n';
    system("pause");
    return 0;
}