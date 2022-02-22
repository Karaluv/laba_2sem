#include <iostream>
#include <cassert>

using namespace std;

// use @ as sum

int get_int()
{

    char c;
    unsigned int result = 0;
    while (cin >> c)
    {
        if (c == '@')
        {
            return result;
        }
        if ((('0' - 1) < c) && (c < ('9' + 1)))
        {
            result *= 16;
            result += c - '0';
        }
        else if ((('A' - 1) < c) && (c < ('F' + 1)))
        {
            result *= 16;
            result += c - 'A' + 10;
        }
    }
    return result;
}

unsigned long long int get_sum()
{
    return get_int() + get_int();
}

int main(int args, char **argv)
{
    cout << get_sum() << '\n';
    system("pause");
    return 0;
}
