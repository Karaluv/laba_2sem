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

int main(int args, char **argv)
{
    assert(check(2000) == false);
    assert(check(13) == true);
    assert(check(2) == true);
    assert(check(1) == false);

    unsigned long long int input_number;
    cin >> input_number;

    cout << check(input_number) << '\n';
    system("pause");
    return 0;
}
