#include <iostream>
#include <cassert>

using namespace std;

//() = 1 -1
//[] = 2 -2
//{} = 3 -3

int get_input()
{
    char c;
    cin >> c;

    switch (c)
    {
    case '(':
        return 1;

    case ')':
        return -1;

    case '[':
        return 2;

    case ']':
        return -2;

    case '{':
        return 3;

    case '}':
        return -3;

    case '@':
        return 0;
    }
    return 0;
}

int recursive_step()
{
    int c = get_input();
    if (c == 0)
        return 1;
    if (c < 0)
        return c;
    else if (recursive_step() == -c)
    {
        return recursive_step();
    }
    else
        return 0;
}

int main(int args, char **argv)
{
    // cassert impossible
    cout << recursive_step() << '\n';
    system("pause");
    return 0;
}
