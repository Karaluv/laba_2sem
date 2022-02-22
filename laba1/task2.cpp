#include <iostream>

using namespace std;

int function_power(int x, unsigned int y)
{
  if (y == 0)
    return 1;
  if (y == 1)
    return x;

  int rec_y = function_power(x, y / 2);

  if (y % 2 == 0)
    return rec_y * rec_y;
  else
    return x * rec_y * rec_y;
}

int main()
{
  int x;
  unsigned int y;

  cin >> x;
  cin >> y;
  cout << function_power(x, y) << '\n';
  system("pause");
  cout << '\n';
  return 0;
}