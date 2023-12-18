#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N;
int board[25][25];
bool isVisited[25][25]; //최대길이 25로 예제에 주어짐
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int totalCnt = 0 ;
queue<pair<int, int>> q; //{x,y} 값 넣을 큐
vector<int> res;

void bfs(void)
{
    int cnt = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        cnt++;
        q.pop(); //for문 앞에선 항상 값 세팅 후 q pop을 해주어야 함.
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i]; //next X, next Y
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny <0 || ny >= N)continue;
            if(isVisited[nx][ny]) continue; //루프문의 끝으로 이동하는 continue(스킵)
            if(board[nx][ny] == 1)
            {
                q.push({nx, ny}); //새로 너비우선탐색할 값을 쌓아주기.
                isVisited[nx][ny] = true;
            }
        }
    }
    res.push_back(cnt);
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(board[i][j] == 1 && isVisited[i][j] == false)
            {
                totalCnt++;
                q.push({i, j});
                isVisited[i][j] = true;
                bfs();
            }
        }
    }
}

int main(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0; j < N; j++)
        {
            board[i][j] = temp[j] - '0'; //temp의 한 자 한 자 int값으로 형변환해 board에 넣어줌
        }
    } //초기화 완
    solve();
    sort(res.begin(), res.end());
    cout << totalCnt << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}