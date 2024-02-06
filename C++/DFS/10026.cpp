#include <iostream>
#include <string.h>
using namespace std;

int N(0), cnt(0);
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
char arr[100][100];
bool isVisited[100][100] = {false,};

void dfs(int x, int y)
{
    isVisited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue; //요 규칙 주의하기.
        if(!isVisited[nx][ny] && arr[x][y] == arr[nx][ny])
            dfs(nx, ny);
    }
}

int main(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!isVisited[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
        for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == 'R') arr[i][j] = 'G';
        }
    }
    memset(isVisited, false, sizeof(isVisited));
    cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!isVisited[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}