#include <iostream>
#include <cassert>

using namespace std;

void int2bit(long long int number)
{
    int c;
    bool start = false;
    for (int i = sizeof(number) * 8 - 1; i >= 0; --i)
    {
        c = ((number >> i) & 1);
        if ((c == 1))
            start = true;
        if (start)
            cout << c;
    }
    cout << '\n';
}

int main(int args, char **argv)
{

    long long int number;
    cin >> number;
    int2bit(number);
    system("pause");
    return 0;
}