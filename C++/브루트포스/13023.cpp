#include <iostream>
#include <vector>

using namespace std;

int N(0), M(0);
vector<int> friends[2001];
bool visited[2001] = {false, };
int ans(0);

void DFS(int depth, int n)
{
    if(depth == 4)
    {
        ans = 1;
        return ;
    }

    for(int i = 0; i < friends[n].size(); i++)
    {
        if(visited[friends[n][i]] == false)
        {
            visited[friends[n][i]] = true;
            DFS(depth + 1, friends[n][i]);
            visited[friends[n][i]] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int a(0), b(0);
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for(int i = 0; i < N; i++)
    {
        if (ans == 1)
            break;  // 답을 찾았으면 더이상 실행하지 않음

        visited[i] = true;
        DFS(0, i);
        visited[i] = false;
    }

    cout << ans << '\n';

    return 0;
}