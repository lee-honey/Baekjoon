#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N(0), M(0), V(0);
bool bIsVisited[1001] = {false,};
vector<int> arr[10001];
queue<int> que;

void DFS(int cur)
{
    bIsVisited[cur] = true;
    cout << cur << " ";
    
    for(int i = 0; i < arr[cur].size(); i++)
    {
        int nextNode = arr[cur][i];
        if(bIsVisited[nextNode] == false)
            DFS(nextNode);
    }
}

void BFS(int cur)
{
    que.push(cur);
    bIsVisited[cur] = true;
    while(!que.empty())
    {
        int cur = que.front();
        cout << cur << " ";
        que.pop();

        for(int i = 0; i < arr[cur].size(); i++)
        {
            int nextNode = arr[cur][i];
            if(bIsVisited[nextNode] == false)
            {
                que.push(nextNode);
                bIsVisited[nextNode] = true;
            }
        }
    }
}

int main(void)
{
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++)
    {
        int A(0), B(0);
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    for(int i = 1; i <= N; i++)
        sort(arr[i].begin(), arr[i].end());

    DFS(V);
    cout << '\n';
    memset(bIsVisited, false, sizeof(bIsVisited));
    BFS(V);

    return 0;
}