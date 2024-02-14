#include <iostream>
#include <queue>
using namespace std;

int N(0), M(0), result(0);
int box[1001][1001] = {0,};
struct tomato
{
    int y,x; //이거 순서를 잘 쓸 것.
};
queue<tomato> q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

void BFS(void)
{
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < M && 0 <= ny && ny < N 
            && box[ny][nx] == 0)
            {
                box[ny][nx] = box[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
} 

int main(void)
{
    cin >> M >> N;
    //일단 입력
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if(box[i][j] == 1)
                q.push({i, j});
        }
    }
    //BFS시작
    BFS();
    //검사
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(box[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
            if(result < box[i][j])
                result = box[i][j];
        }
    }
    cout << result - 1 << endl;
    return 0;
}