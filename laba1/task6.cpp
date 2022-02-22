#include <iostream>

using namespace std;

int main()
{

    int n;
    int max = 0;
    int s = 0;
    int np = -1U >> 1;
    while (cin >> n)
    {
        if (n > np)
            s++;
        else
        {
            max = (s > max) * s + (s <= max) * max;
            s = 0;
        }
        np = n;
    }
    max = (s > max) * s + (s <= max) * max;
    cout << max << '\n';

    system("pause");
    cout << '\n';
    return 0;
}
