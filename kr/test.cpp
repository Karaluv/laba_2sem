// ProblemD.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
    int x,y,z,a,b,c;
    int temp;
    for (int i = 0; i < (data_end - data_start) - N+1; i++)
    {
        int ch_left = 0;
        int ch_right = 0;
        int ch_back = 0;
        int ch_meow = 0;
        for (int j = 0; j < N; j++)
        {
            ch_back = ch_back+abs(back[j] - *(data_start+i + j));
            ch_left = ch_left+abs(left[j] - *(data_start+i + j));
            ch_meow = ch_meow+abs(meow[j] - *(data_start+i + j));
            ch_right = ch_right+abs(right[j] - *(data_start+i + j));
            
            
        }
        *command = 1;
        if (ch_left == 0)
        {
            *frame = (data_start+i);
            return;
        }
        (*command)++;
        if (ch_right == 0)
        {
            *frame = (data_start+i);
            return;
        }
        (*command)++;
        if (ch_back == 0)
        {
            *frame = (data_start+i);
            return;
        }
        (*command)++;
        if (ch_meow == 0)
        {
            *frame =  (data_start+i);
            return;
        }
    }
    *command = 0;
    *frame = nullptr;
    return;
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.