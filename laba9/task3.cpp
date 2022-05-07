#include <iostream>

using namespace std;

struct count_double{
    long long int count1 = 0;
    long long int count2 = 0;
};

count_double universes_count(long long int p1, long long int p2, long long int s1, long long int s2, long long int turn, count_double***** memory){
    if(memory[p1][p2][s1][s2][turn].count1 != 0 or memory[p1][p2][s1][s2][turn].count2 != 0){
        return memory[p1][p2][s1][s2][turn];
    }
    if(s1 >= 21){
        count_double v;
        v.count1 = 1;
        return v;
    }
    if(s2 >= 21){
        count_double v;
        v.count2 = 1;
        return v;
    }
    long long int p_1, p_2, s_1, s_2;
    count_double uni_counted;
    for(long long int i = 1; i <= 3; ++i){
        for(long long int j = 1; j <= 3; ++j){
            for(long long int k = 1; k <=3; ++k){
                s_1 = s1;
                s_2 = s2;
                if(turn == 0){
                    p_1 = (p1 + i + j + k)%10;
                    s_1 += p_1;
                    if(s_1 >= 21){
                        count_double win;
                        win.count1 = 1;
                        uni_counted.count1 += win.count1;
                        uni_counted.count2 += win.count2;
                    }
                    else{
                        count_double uni = universes_count(p_1, p2, s_1, s2, 1, memory);
                        uni_counted.count1 += uni.count1;
                        uni_counted.count2 += uni.count2;
                    }
                }
                else{
                    p_2 = (p2 + i + j + k)%10;
                    s_2 += p_2;
                    if(s_2 >= 21){
                        count_double win;
                        win.count2 = 1;
                        uni_counted.count1 += win.count1;
                        uni_counted.count2 += win.count2;
                    }
                    else{
                        count_double uni = universes_count(p1, p_2, s1, s_2, 0, memory);
                        uni_counted.count1 += uni.count1;
                        uni_counted.count2 += uni.count2;
                    }
                }
            }
        }
    }
    if(memory[p1][p2][s1][s2][turn].count1 == 0 and memory[p1][p2][s1][s2][turn].count2 == 0){
        memory[p1][p2][s1][s2][turn] = uni_counted;
    }
    return uni_counted;
}

int main()
{
    long long int p1, p2, s1 = 6, s2 = 6, turn = 0;
    cin >>p1 >>p2;
    count_double***** memory = new count_double****[10];
    for(long long int i = 0; i < 10; ++i){
        memory[i] = new count_double***[10];
        for(long long int j = 0; j < 10; ++j){
            memory[i][j] = new count_double**[21];
            for(long long int k = 0; k < 21; ++k){
                memory[i][j][k] = new count_double*[21];
                for(long long int l = 0; l < 21; ++l){
                    memory[i][j][k][l] = new count_double[2];
                }
            }
        }
    }
    count_double total_count;
    total_count = universes_count(p1, p2, s1, s2, turn, memory);
    cout <<"1 Player: " <<total_count.count1 << "       2 Player: " <<total_count.count2;
    return 0;
}
