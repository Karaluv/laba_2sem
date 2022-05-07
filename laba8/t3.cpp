#include <iostream>

using namespace std;

int* Money_Exchange(int N, int Nominal[], int** Memory){
    if(Memory[N-1] != nullptr){
        return Memory[N-1];
    }
    if(N < 1){
        return nullptr;
    }
    int minimum = N;
    int sum;
    int* Optimal = new int[5];
    for(int i = 0; i < 5; i++){
        Optimal[i] = 0;
    }
    for(int i = 0; i < 5; i++){
        if(N == Nominal[i]){
            Optimal[i] = 1;
            return Optimal;
        }
    }

    for(int i = 0; i < 5; i++){
        if(N-1 - Nominal[i] >= 0){
            sum = 0;
            Memory[N-1 - Nominal[i]] = Money_Exchange(N - Nominal[i], Nominal, Memory);
            for(int j = 0; j < 5; j++){
                sum += Memory[N-1 - Nominal[i]][j];
            }
            if(sum <= minimum){
                minimum = sum;
                for(int k = 0; k < 5; k++){
                    Optimal[k] = Memory[N-1 - Nominal[i]][k];
                }
                Optimal[i] ++;
            }
        }
    }
    Memory[N-1] = Optimal;
    return Optimal;
}

int main()
{
    //initializing
    int Nominal[5];
    Nominal[0] = 1;
    Nominal[1] = 2;
    Nominal[2] = 5;
    Nominal[3] = 7;
    Nominal[4] = 10;

    int N;
    cin >>N;

    int ** Memory = new int* [N];
    for(int i = 0; i < N; ++i){
        Memory[i] = nullptr;
    }
    //initializing



    int* Optimal;
    if(N > 100){
    Optimal = Money_Exchange(100 + (N-100)%10, Nominal, Memory);
    Optimal[4] += (N-100)/10;
    }
    else{
        Optimal = Money_Exchange(N, Nominal, Memory);
    }
    int Sum = 0;
    cout <<"\n";
    for(int i = 0; i < 5; i++){
        cout <<Nominal[i] <<" ";
    }
    cout <<"\n";
    for(int i = 0; i < 5; i++){
        cout <<"| ";
    }
    cout <<"\n";
    for(int i = 0; i < 5; i++){
        Sum += Optimal[i];
        cout <<Optimal[i] <<" ";
    }
    cout <<"\n\nTotal min = " <<Sum <<"\n";
    return 0;
}
