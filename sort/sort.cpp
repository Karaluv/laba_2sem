#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>

using namespace std;

int GetLen(int length, bool first)
{
    return (length / 2 + (length % 2) * (first));
}

int &cut_array(int *array2cut, int length_1)
{
    return *(array2cut + length_1);
}

void sort_small_array(int *array, int length)
{
    bool found = false;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                found = true;
            }
        }
        if (!found)
        {
            break;
        }
        found = false;
    }
}

void compose_arrays(int *arr_1, int *arr_2, int length_1, int length_2, int *array_return)
{
    int i = 0;
    int j = 0;

    int dump_arr[length_1 + length_2];

    if ((length_1 > 4) || (length_2 > 4))
    {
        compose_arrays(arr_1, &cut_array(arr_1, GetLen(length_1, true)), GetLen(length_1, true), GetLen(length_1, false), dump_arr);
        arr_1 = dump_arr;

        compose_arrays(arr_2, &cut_array(arr_2, GetLen(length_2, true)), GetLen(length_2, true), GetLen(length_2, false), dump_arr + length_1);
        arr_2 = dump_arr + length_1;
    }
    else
    {
        sort_small_array(arr_1, length_1);
        sort_small_array(arr_2, length_2);
    }
    while (i + j < length_1 + length_2)
    {
        if (((arr_1[i] < arr_2[j]) && (i < length_1)) || (j == length_2))
        {
            array_return[i + j] = arr_1[i];
            i++;
        }
        else
        {
            array_return[i + j] = arr_2[j];
            j++;
        }
    }
}

void sort_it(int array2sort[], int length, int array_output[])
{
    compose_arrays(array2sort, &cut_array(array2sort, GetLen(length, false)), GetLen(length, true), GetLen(length, false), array_output);
}

void generate_array(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = (rand() % 10);
    }
}

void check()
{
    int length = 1000;
    int array2sort[length];
    int array_output[length];
    generate_array(array2sort, length);

    sort_it(array2sort, length, array_output);

    sort(array2sort, array2sort + length);

    for (int i = 0; i < length; i++)
        if (array2sort[i] != array_output[i])
            cout << "error!!!";
}

int main(int args, char **argv)
{

    check();

    int array2sort[] = {4, 2, 5, 6, 1, 3, 17, 14, 67, 45, 32, 66, 88,
                        78, 69, 92, 93, 21, 25, 23, 71, 61, 59, 60, 30};

    int length = 25;

    int array_output[length];

    sort_it(array2sort, length, array_output);

    cout << '\n';
    for (int i = 0; i < length; i++)
        cout << array_output[i] << ' ';

    std::cout << '\n'
              << "End" << '\n';
    // system("pause");
    return 0;
}