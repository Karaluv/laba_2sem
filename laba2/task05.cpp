#include <iostream>
#include <cassert>

using namespace std;

unsigned long long int new_itter(int number)
{
    if (number == 0)
        return 1;
    if (number == 1)
        return 1;

    return new_itter(number - 1) * number;
}

int main(int args, char **argv)
{
    assert(new_itter(0) == 1);
    assert(new_itter(1) == 1);
    assert(new_itter(4) == 24);

    int number;
    cin >> number;
    cout << new_itter(number) << '\n';

    system("pause");
    return 0;
}
