#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

int recursion(int arr[], int length, int index, int score)
{
int temp = score;
for (int i =index+1; i<length; i++)
{
    if (arr[i]>arr[index])
    temp = max(recursion(arr,length, i,score+1), temp);
}
score = temp;
return score;

}

int start_recursion(int arr[], int length)
{

    int score = 0;

for (int i =0; i<length; i++)
{
    score = max(recursion(arr,length, i,0), score);
}

return score;

}


int main(int args, char **argv)
{

 int n;


 cin >> n;

auto arr = new int[n];


for (int i =0;i<n;++i)
cin >> arr[i];

cout << (start_recursion(arr,n)+1);





    return 0;
}