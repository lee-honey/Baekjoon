#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N(0), a(0);
vector<int> vec[100];
bool visit[100];

void DFS(int x)
{
    for(int i = 0; i < vec[x].size(); i++)
    {
        if(!visit[vec[x][i]])
        {
            visit[vec[x][i]] = true;
            DFS(vec[x][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> a;
            if(a == 1)  vec[i].push_back(j);
        }
    }

    for(int i = 0; i < N; i++)
    {
        memset(visit, false, sizeof(visit));
        DFS(i);
        for(int j = 0; j < N; j++)
            cout << visit[j] << " ";
        cout << '\n';
    }

    return 0;
}