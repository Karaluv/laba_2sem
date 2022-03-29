#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>
#include <chrono>
#define _USE_MATH_DEFINES           // for C++
#define M_PI 3.14159265358979323846 /* pi */
#include <cmath>

using namespace std;

double pi_teylor(int n)
{
    //teylor
    double sum = 0.0;
    int sign = 1;
    int i = 0;
    auto res = static_cast<double>(1) / n;
    while (abs(sum * 4.0 - M_PI) > res)
    {

        sum += sign / (2.0 * i + 1.0);
        sign *= -1;
        i++;
    }
    return 4.0 * sum;
}

double pi_itter(int n)
{
    // There are three other Machin-like formulas, as well as thousands of other similar formulas having more terms.
    int c = 0;
    double pi = 0;
    double a = 1;
    auto res = static_cast<double>(1) / n;
    while (abs(pi - M_PI) > res)
    {
        if (c == 0)
        {
            pi = pi + 4 / a;
            c++;
        }
        else
        {
            pi = pi - 4 / a;
            c--;
        }
        a += 2;
    }
    return pi;
}

double pi_itter2(int n)
{
        // There are three other Machin-like formulas, as well as thousands of other similar formulas having more terms.
    int c = 0;
    double pi = 3;
    double a = 2;
    auto res = static_cast<double>(1) / n;
    while (abs(pi - M_PI) > res)
    {
        if (c == 0)
        {
            pi = pi + 4 / (a*(a+1)*(a+2));
            c++;
        }
        else
        {
            pi = pi - 4 / (a*(a+1)*(a+2));
            c--;
        }
        a += 2;
    }
    return pi;
}

int main(int args, char **argv)
{
    int acc = 10000000;
for (acc = 10000000; acc<=10000000; acc = acc*10)
{
    {
        auto start = std::chrono::high_resolution_clock::now();
        //cout << pi_itter(acc) << '\n';
        pi_itter(acc);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        std::cout << nsec.count()<< std::endl;
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        //cout << pi_teylor(acc) << '\n';
        pi_teylor(acc);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        std::cout << nsec.count() << std::endl;
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        //cout << pi_itter2(acc) << '\n';
        pi_itter2(acc);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        std::cout << nsec.count() << std::endl;
    }
}

    // system("pause");
    return 0;
}