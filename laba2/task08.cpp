#include <iostream>
#include <cassert>

using namespace std;

int get_int()
{

    char c;
    unsigned int index;
    unsigned int result = 0;
    while (cin >> c)
    {
        if (c == '@')
        {
            return result;
        }
        index = (int)c - '0';
        if (index < 2)
        {
            result *= 2;
            result += index;
        }
    }
    return result;
}

int main(int args, char **argv)
{
    cout << get_int() << '\n';
    system("pause");
    return 0;
}
