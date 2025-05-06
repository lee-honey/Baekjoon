#include <iostream>

using namespace std;

int N(0), M(0);
int r(0), c(0), d(0);
int arr[51][51] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int lx[4] = {-1, 0, 1, 0};
int ly[4] = {0, 1, 0, -1};
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    int cx = r;
    int cy = c;
    int cd = d;

    while(1)
    {
        if(arr[cx][cy] == 0)
        {
            arr[cx][cy] = -1;
            ans++;
        }

        bool bHaveToClear = false;
        for(int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if(arr[nx][ny] == 0)
                    bHaveToClear = true;
            }
        }
        if(bHaveToClear == false)
        {
            int nx = cx - lx[cd];
            int ny = cy - ly[cd];
            if(0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if(arr[nx][ny] == 1)
                    break;
                else
                {
                    cx = nx;
                    cy = ny;
                    continue;
                }                
            }
        }
        else
        {
            cd = (cd + 4 - 1) % 4;
            int nx = cx + lx[cd];
            int ny = cy + ly[cd];
            if(0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if(arr[nx][ny] == 0)
                {
                    cx = nx;
                    cy = ny;
                    continue;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}