#include <iostream>

using namespace std;

void min_dist(int N, int* A, int** Treks){
    Treks[0][0] = 1;
    Treks[1][1] = 1;
    int m1, m2;
    for(int i = 2; i < N + 1; i++){
        m1 = 0;
        m2 = 0;
        for(int j = 0; j < i; j++){
            m1 = m1 + (A[j]*Treks[i-1][j]);
            m2 = m2 + (A[j]*Treks[i-2][j]);
        }
        if(m1 > m2){
            Treks[i][i] = 1;
            for(int j = 0; j < i; j++){
                Treks[i][j] = Treks[i-2][j];
            }
        }
        else{
            Treks[i][i] = 1;
            for(int j = 0; j < i; j++){
                Treks[i][j] = Treks[i-1][j];
            }
        }
    }
    return;
}

int main()
{
    int N;
    cin >>N;
    int* A = new int [N + 1];
    int** Treks = new int* [N+1];
    A[N] = 0;
    for(int i = 0; i < N; ++i){
        cin >>A[i];
    }
    for(int i = 0; i < N + 1; ++i){
        Treks[i] = new int [N+1];
        for(int j = 0; j < N+1; ++j){
            Treks[i][j] = 0;
        }
    }

    min_dist(N, A, Treks);
    cout <<endl;
    for(int i = 0; i < N; i++){
        cout << i+1 <<" ";
    }
    cout <<endl;
    for(int i = 0; i < N; i++){
        cout <<"| ";
    }
    cout <<endl;
    int s =0;
    for(int i = 0; i < N; i++){
        cout <<Treks[N][i] <<" ";
        s += A[i]*Treks[N][i];
    }
    cout <<endl <<s <<endl;
    return 0;
}
