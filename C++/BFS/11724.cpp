#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, u, v;
vector<int> vect[1001]; // 벡터와 배열의 콜라보레이션
bool isVisited[1001];
int totalCnt = 0 ;
queue<int> q;

void bfs(void) //너비우선은 끝까지 가면 종료됨
{
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        for(int i = 0; i < vect[idx].size(); i++)
        {
            int temp = vect[idx][i];
            if(isVisited[temp]) continue; //루프문의 끝으로 이동하는 continue(스킵)
            q.push(temp);
            isVisited[temp] = true;
        }
    }
}

int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u);
    }
    for(int i = 1; i <= N; i++) //시작 노드를 변경하면서 bfs를 N번 실행
    {
        if(isVisited[i] == false)
        {
            q.push(i);
            isVisited[i] = true;
            bfs();
            totalCnt++;
        }
    }
    cout << totalCnt << '\n';
    return 0;
}