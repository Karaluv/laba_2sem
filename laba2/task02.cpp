#include <iostream>

using namespace std;

const int start_index = 48;
const int end_index = 57;

unsigned long long int get_int()
{

    char c;
    char index;
    unsigned long long int result = 0;
    while (cin >> c)
    {
        if (c == '@')
        {
            return result;
        }
        index = (int)c - '0';
        if (index < 10)
        {
            result *= 10;
            result += index;
        }
    }
    return result;
}

int main(int args, char **argv)
{
    //assert imposible beacause function has no input
    cout << get_int() << '\n';
    system("pause");
    return 0;
}
