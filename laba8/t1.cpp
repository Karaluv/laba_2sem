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
#include <vector>

using namespace std;

int recursion_step(int len, int n, int zapr, int arr[], int L, int way, int procced_way)
{

    if (procced_way + 10 >= way)
        return n;

    int delta = 1;

    auto k = delta + zapr;
    // cout << k;
    int best = 100000000;
    int temp;

    while ((arr[zapr + delta] - procced_way <= L) && (zapr + delta < len))
    {

        temp = recursion_step(len, n + 1, zapr + delta, arr, L, way, arr[zapr + delta]);
        if (temp < best)
        {
            zapr = arr[zapr + delta];
            best = temp;
        }
        delta++;
    }
    cout << zapr << '\n';
    return best;
}

int get_zaprav(int len, int arr[], int L, int way)
{

    return recursion_step(len, 0, -1, arr, L, way, 0);
}

int main(int args, char **argv)
{

    int L = 10;
    int way = 24;
    int length = 3;
    int arr[length] = {5, 9, 15, 18};
    cout << get_zaprav(length, arr, L, way);
    std::cout << '\n'
              << "End" << '\n';
    // system("pause");
    return 0;
}