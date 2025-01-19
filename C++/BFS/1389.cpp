#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0, M = 0, iNum = 0, iResult = 2147483647;
vector<int> People[101];

int BFS(int iStart, int iEnd)
{
    bool bVisited[101] = {false, };
    queue<pair<int, int>> q;
    q.push(make_pair(iStart, 0));
    bVisited[iStart] = true;
    int iResult = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(x == iEnd)
        {
            iResult = depth;
            break;
        }

        for(int i = 0; i < People[x].size(); i++)
        {
            if(!bVisited[People[x][i]])
            {
                q.push(make_pair(People[x][i], depth + 1));
                bVisited[People[x][i]] = true;
            }
        }
    }

    return iResult;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        People[a].push_back(b);
        People[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) // 1에서부터 N까지인것을 주의할 것.
    {
        int iTemp = 0;
        for(int j = 1; j <= N; j++)
        {
            if(i == j)
                continue;
            
            iTemp += BFS(i, j);
        }
        if(iResult > iTemp)
        {
            iResult = iTemp;
            iNum = i;
        }
    }

    cout << iNum << '\n';

    return 0;
}