#include <iostream>

using namespace std;

int main()
{
    int L,N;
    cin >>L >>N;
    int stages[N]; // haha
    stages[0] = 0;
    for(int i = 1; i < N+1; i++){
        cin >>stages[i];
    }
    int n = 0;
    int position = 0;
    for(int i = position + 1; i < N+1; i++){
        if(stages[i] - stages[position] > L){
            if(i-1 == position){
                cout <<"to big distance" <<i-1 <<'\t' <<i  <<'\n';
                return 0;
            }
            position = i-1;
            n++;
            cout <<"Refuel at stage " <<i-1 <<'\n';
            i--;
        }
    }
    cout <<'\t' <<n;
    return 0;
}
