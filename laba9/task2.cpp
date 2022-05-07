#include <iostream>

using namespace std;

int main()
{
    int n_colors;
    cin >> n_colors;
    int *colors = new int[n_colors];
    for (int i = 0; i < n_colors; ++i)
    {
        colors[i] = -1;
    }
    int N, M;
    cin >> N >> M;
    int **A = new int *[N];
    int ***Dist = new int **[4];
    for (int i = 0; i < 4; ++i)
    {
        Dist[i] = new int *[N];
    }
    for (int i = 0; i < N; ++i)
    {
        A[i] = new int[M];
        for (int k = 0; k < 4; ++k)
        {
            Dist[k][i] = new int[M];
        }
        for (int j = 0; j < M; ++j)
        {
            cin >> A[i][j];
            for (int k = 0; k < 4; ++k)
            {
                Dist[k][i][j] = 1;
            }
        }
    }
    int l;
    int o = 0;
    for (int i1 = 0; i1 < N; ++i1)
    {
        for (int j1 = 0; j1 < M; ++j1)
        {
            l = 0;
            colors[o] = A[i1][j1];
            for (int j = 0; j < o; ++j)
            {
                if (colors[o] == colors[j])
                {
                    l = 1;
                }
            }
            if (l == 0)
            {
                o++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 or
                j == 0 or
                i == N - 1 or
                j == M - 1 or
                A[i][j] != A[i + 1][j] or
                A[i][j] != A[i][j + 1] or
                A[i][j] != A[i - 1][j] or
                A[i][j] != A[i][j - 1])
            {
                for (int k = 0; k < 4; k++)
                {
                    Dist[k][i][j] = 0;
                }
            }
        }
    }
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < M - 1; j++)
        {
            if (Dist[0][i][j] != 0)
            {
                Dist[0][i][j] = min(Dist[0][i - 1][j], Dist[0][i][j - 1]) + 1;
            }
        }
    }
    for (int i = N - 2; i > 0; i--)
    {
        for (int j = 1; j < M - 1; j++)
        {
            if (Dist[0][i][j] != 0)
            {
                Dist[1][i][j] = min(Dist[0][i + 1][j], Dist[0][i][j - 1]) + 1;
            }
        }
    }
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = M - 2; j > 0; j--)
        {
            if (Dist[0][i][j] != 0)
            {
                Dist[2][i][j] = min(Dist[0][i - 1][j], Dist[0][i][j + 1]) + 1;
            }
        }
    }
    for (int i = N - 2; i > 0; i--)
    {
        for (int j = M - 2; j > 0; j--)
        {
            if (Dist[0][i][j] != 0)
            {
                Dist[3][i][j] = min(Dist[0][i + 1][j], Dist[0][i][j + 1]) + 1;
            }
        }
    }

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < M - 1; j++)
        {
            Dist[0][i][j] = min(Dist[3][i][j], min(Dist[2][i][j], min(Dist[0][i][j], Dist[1][i][j])));
        }
    }

    int Max_color[n_colors][3];
    for (int i = 0; i < n_colors; i++)
    {
        Max_color[i][0] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < n_colors; k++)
            {
                if (Dist[0][i][j] >= Max_color[k][0] and A[i][j] == colors[k])
                {
                    Max_color[k][0] = Dist[0][i][j];
                    Max_color[k][1] = i;
                    Max_color[k][2] = j;
                }
            }
        }
    }

    cout << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << Dist[0][i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int k = 0; k < n_colors; k++)
    {
        cout << "For color " << colors[k] << " center is (" << Max_color[k][1] + 1 << ";" << Max_color[k][2] + 1 << ") and distance = " << Max_color[k][0] << endl;
    }
    cout << endl;

    return 0;
}
