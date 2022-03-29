#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

void merge(long *arr_1, long *end_1, long *arr_2, long *end_2, long *array_return)
{
  long i = 0;
  long j = 0;

  while (((arr_1 + i) != end_1) || ((arr_2 + j) != end_2))
  {
    if (arr_1 + i != end_1)
      if (arr_2 + j != end_2)
      {
        if (arr_1[i] < arr_2[j])
        {
      array_return[i + j] = arr_1[i];
      i++; 
        }
      }
      else
      {
      array_return[i + j] = arr_1[i];
      i++;
      }
    if (arr_2 + j != end_2)
      if (arr_1 + i != end_1)
      {
        if (arr_2[j] < arr_1[i])
        {
      array_return[i + j] = arr_2[j];
      j++; 
        }
      }
      else
      {
      array_return[i + j] = arr_2[j];
      j++;
      }


  }
}

int main(int args, char **argv)
{

  {
    auto const N_a = 10, N_b = 15;
    std::mt19937_64 eng{42};
    std::uniform_int_distribution<long> uni{-1000, 1000};
    long *a = new long[N_a];
    long *b = new long[N_b];
    for (auto i = 0; i < N_b; ++i)
      b[i] = uni(eng);
    for (auto i = 0; i < N_a; ++i)
      a[i] = uni(eng);

    std::sort(a, a + N_a);
    std::sort(b, b + N_b);

    long *out = new long[N_a + N_b];
    merge(a, a + N_a, b, b + N_b, out);
    for (int i = 0; i < N_a + N_b; i++)
      cout << *(out + i) << '\n';

    for (auto i = 1; i < N_a + N_b; ++i)
      if (out[i - 1] > out[i])
        std::cout << i << " " << out[i - 1] << " " << out[i] << "\n";

    delete[] a;
    delete[] b;
    delete[] out;
  }
  std::cout << '\n'
            << "End" << '\n';
  // system("pause");
  return 0;
}