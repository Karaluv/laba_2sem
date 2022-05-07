#include <iostream>
#include <algorithm>
#include <string>


using namespace std;


int recursion(int arr[], int length, int x,int y)
{
    static int points = 0;
if (y  == 7)
points +=1;
if (arr[x+8*(y+1)-1] == 1)
recursion(arr, length, x-1,y+1);

if (arr[x+8*(y+1)+1] == 1)
recursion(arr, length, x+1,y+1);


if (arr[x+8*(y+1)] == 0)
recursion(arr, length, x,y+1);

return points;

}

int start_recursion(int arr[], int length, int x,int y)
{
return recursion(arr,length, x,y);


}


int main()
{

 int n;


 cin >> n;

auto arr = new int[8*8];

for (int i = 0;i<64;++i)
arr[i] = 0;


char ox, oy;




for (int i =0;i<n;++i)
{
cin >> oy;
cin >> ox;

oy = oy - 'a';
ox = ox - '1';


arr[(7 - ox)*8+oy]=1;
}

int x,y;
{
char tx,ty;
cin >> ty >> tx;
ty = ty-'a';
tx = tx-'1';

y = (int)tx;
x = 7 - (int)ty;
}

for(int i =0; i<8;i++)
{
    cout<<'\n';
for(int j =0; j<8;j++)
cout << arr[i*8+j];


}
cout<<'\n';

cout << start_recursion(arr, n , x,y);

    return 0;
}