#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

bool check(long long int number2check)
{
    if (number2check == 2)
        return true;
    if (number2check == 1)
        return false;
    if (number2check % 2 == 0)
        return false;
    for (long int i = 3; i < ((int)std::sqrt(number2check) + 1); i += 1)
        if (number2check % i == 0)
            return false;
    return true;
}

int get_number_called(bool is_reset)
{

    static unsigned int min = 1;
    min += 1;
    if (is_reset)
        min = 1;
    else
        while (true)
        {
            if (check(min))
            {
                break;
            }
            min += 1;
        }
    return min;
}

void reset_number()
{
    get_number_called(true);
}

int get_number()
{
    return get_number_called(false);
}

int main(int args, char **argv)
{
    
    assert(check(1) == false);
    assert(check(2) == true);
    assert(get_number() == 2);
    reset_number();
    assert(get_number() == 2);
    assert(get_number() == 3);
    reset_number();

    char c;

    while (cin >> c)
    {
        if (c == '@')
            break;
        if (c == 'r')
        {
            reset_number();
        }
        if (c == 'i')
        {
            cout << get_number() << '\n';
        }
    }

    system("pause");
    return 0;
}
