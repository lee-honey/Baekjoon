#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int N(0), cnt(0);
char arr[100][100];
bool isVisited[100][100] = {false,};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y){
    isVisited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
        if(!isVisited[nx][ny] && arr[x][y] == arr[nx][ny])
            dfs(nx, ny);
    }
}

int Count(void)
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!isVisited[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cout <<  Count() << " ";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == 'R') arr[i][j] = 'G';
        }
    }
    memset(isVisited, false, sizeof(isVisited));
    cnt = 0;
    cout << Count()<<endl;
    return 0;
}