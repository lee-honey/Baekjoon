#include <iostream>

using namespace std;

typedef struct _Pipe{
    int horiz;      // 가로
    int diag;       // 대각선
    int verti;      // 세로
} pipe;

int N(0);
pipe cases[17][17];
int map[17][17];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
    
    for(int j = 0; j < N; j++)  // 초기화
    {
        if(map[0][j])
            break;
        cases[0][j].horiz = 1;
    }

    for(int i = 1; i < N; i++){
        for(int j = 2; j < N; j++){
            if(!map[i][j]){
                cases[i][j].horiz = cases[i][j - 1].horiz + cases[i][j - 1].diag;
				cases[i][j].verti = cases[i - 1][j].diag + cases[i - 1][j].verti;
				if (!map[i][j - 1] && !map[i - 1][j - 1] && !map[i - 1][j])
					cases[i][j].diag = cases[i - 1][j - 1].horiz + cases[i - 1][j - 1].diag + cases[i - 1][j - 1].verti;
            }
        }
    }

    cout << cases[N-1][N-1].horiz + cases[N-1][N-1].diag + cases[N-1][N-1].verti << '\n'; 

    return 0;
}