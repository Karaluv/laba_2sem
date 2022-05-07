#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

int recursion(int arr[], int length, int index, int score)
{

if (index == length-1)
return score;


int v1 = 999999;
int v2 = 999999;

v1 = recursion(arr,length, index+1,score+abs(arr[index]-arr[index+1]));
if (index+2<length)
v2 = recursion(arr,length, index+2, score + score+abs(arr[index]-arr[index+2]));
score = min(v1,v2);
return score;

}

int start_recursion(int arr[], int length)
{

    int score = 0;

return recursion(arr,length, 0,0);

}


int main(int args, char **argv)
{

 int n=0;

auto arr = new int[1000];



while (cin >> arr[n])
n++;




cout << (start_recursion(arr,n));





    return 0;
}