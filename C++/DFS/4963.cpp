#include <iostream>

using namespace std;

int w(0), h(0);
int ans(0);
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};

void DFS(int x, int y, bool visited[51][51], int arr[51][51])
{
    visited[x][y] = true;
    
    for(int i = 0; i < 8; i++)
    {
        int nh = x + dx[i];
        int nw = y + dy[i];

        if(0<= nh && nh < h && 0 <= nw && nw < w
        && arr[nh][nw] == 1 && visited[nh][nw] == false)
            DFS(nh, nw, visited, arr);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        cin >> w >> h;
        int arr[51][51] = {0,};
        bool visited[51][51] = {false,};

        ans = 0;

        if(w == 0 && h == 0)
            break;
        
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> arr[i][j];

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(arr[i][j] == 1 && visited[i][j] == false)
                {
                    ans++;
                    DFS(i, j, visited, arr);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}