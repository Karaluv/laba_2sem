#include <iostream>

using namespace std;


int main()
{
unsigned int n;


int min = -1U >> 1;
int res = -1U >> 1;
int input;
while (cin >> input)
{
    int x;
    x = input % 101;
    
    if (x<0)
    x += 101;
    if (x < min)
    {
        min = x;
        res = input;
    }
    else if (x == min)
    res = (res>input)*(res-input) + input;

}
cout << res << '\n';
system("pause");
return 0;
}
