#include <iostream>
using std::cout;
using std::endl;

const unsigned int N = 5;
const int left[N] = {5, 4, 3, 2, 1};  // command code 1
const int right[N] = {1, 2, 3, 4, 5}; // command code 2
const int back[N] = {1, 1, 1, 1, 1};  // command code 3
const int meow[N] = {3, 2, 3, 2, 5};  // command code 4

void recognize(int *data_start, int *data_end, int *command, int **frame)
{
    for (auto i = data_start; i < data_end - N + 1; ++i)
    {
        int ch_left = 0;
        int ch_right = 0;
        int ch_back = 0;
        int ch_meow = 0;
        
        for (unsigned j = 0; j < N; ++j)
        {
            ch_left += abs(left[j] - *(i + j));
            ch_right += abs(right[j] - *(i + j));
            ch_back += abs(back[j] - *(i + j));
            ch_meow += abs(meow[j] - *(i + j));
        }
        if (ch_left == 0)
        {
            *command = 1;
            *frame = i;
            return;
        }
        if (ch_right == 0)
        {
            *command = 2;
            *frame = i;
            return;
        }
        if (ch_back == 0)
        {
            *command = 3;
            *frame = i;
            return;
        }
        if (ch_meow == 0)
        {
            *command = 4;
            *frame = i;
            return;
        }
    }
    *command = 0;
    *frame = nullptr;
}

int main()
{
    const int L = 21;
    int mindstream[L] = {3, 2, 3, 2, 5, 2, 3, 8, 3, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5};
    int command = -1;
    int *frame = mindstream;
    int *end = mindstream + L;
    while (command)
    {
        recognize(frame, end, &command, &frame);
        if (!command)
            break;
        switch (command)
        {
        case 1:
            cout << "left ";
            break;
        case 2:
            cout << "right ";
            break;
        case 3:
            cout << "back ";
            break;
        case 4:
            cout << "MEOOOOW ";
            break;
        }
        frame += N;
    }
    cout << endl;
    return 0;
}