#include <iostream>

using namespace std;

int main()
{
    unsigned int n;

    int min = -1U >> 1;
    int input;
    while (cin >> input)
    {
        cout << '\n';
        min = (input < min) * input + (input >= min) * min;
    }
    cout << "min: " << min << '\n';
    system("pause");
    return 0;
}
