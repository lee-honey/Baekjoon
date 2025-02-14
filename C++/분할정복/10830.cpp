#include <iostream>

using namespace std;

long long N(0), B(0);
long long a[5][5];
long long ans[5][5];
long long temp[5][5];

void Mat(long long x[5][5],long long y[5][5])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            temp[i][j] = 0;
            for(int k = 0; k < N; k++)
            {
                temp[i][j] += (x[i][k] * y[k][j]);
            }
            temp[i][j] %= 1000;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            x[i][j] = temp[i][j];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
        ans[i][i] = 1;  // 정답행렬 단위행렬로 초기화
    }

    while(B > 0){
        if(B % 2 == 1)
            Mat(ans, a);
        Mat(a, a);
        B /= 2;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}