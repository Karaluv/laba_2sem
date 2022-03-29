#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>

using namespace std;

void rec_step(int arr[], int n, int i)
{
    int lg = i;   
    int l = 2*i + 1;
    int r = 2*i + 2; 

    if ((l < n) && (arr[l] > arr[lg]))
        lg = l;

    if ((r < n) && (arr[r] > arr[lg]))
        lg = r;
    if (lg != i)
    {
        swap(arr[i], arr[lg]);
        rec_step(arr, n, lg);
    }
}

void sort_it(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        rec_step(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        rec_step(arr, i, 0);
    }
}

void generate_array(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = (rand());
    }
}

void check()
{
    int length =100000;
    int array2sort[length];
    int array2copy[length];
    generate_array(array2sort, length);
    for (int i = 0; i<length;i++)
    array2copy[i] = array2sort[i];

    sort_it(array2copy, length);

    sort(array2sort, array2sort + length);

    for (int i = 0; i < length; i++)
        if (array2copy[i] != array2sort[i])
            cout << "error!!!";
}

int main(int args, char **argv)
{

    check();

    int array2sort[] = {4, 2, 5, 6, 1, 3, 17, 14, 67, 45, 32, 66, 88,
                        78, 69, 92, 93, 21, 25, 23, 71, 61, 59, 60, 30};

    int length = 25;

    sort_it(array2sort,length);
    cout << '\n';
    for (int i = 0; i < length; i++)
        cout << array2sort[i] << ' ';

    std::cout << '\n'
              << "End" << '\n';
    // system("pause");
    return 0;

}