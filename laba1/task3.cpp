#include <iostream>

using namespace std;

inline void print_out(char symb, int n)
{
for (n; n>0; n--)
cout << symb;

}

int main()
{
unsigned int n;
cout << "Enter N: ";
cin >> n; 
cout << '\n';
if (n % 5 == 0)
print_out('@',n);
else
print_out('%',n);
cout << '\n';
system("pause");
return 0;
}
