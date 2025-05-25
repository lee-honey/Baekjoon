#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

struct point
{
    int x; int y;
};
point store[100];
point festival;
point home;
bool visited[100];

bool BFS(int n)
{
    queue<pair<int, int>> que;
    que.push({home.x, home.y});

    while(!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        if(abs(festival.x - x) + abs(festival.y - y) <= 1000) 
            return true;
        for(int i = 0; i < n; i++) // que에 넣는 애의 기준이 방문하고자 하는 편의점이 됨
        {
            if(visited[i] == true)
                continue;
            if(abs(store[i].x - x) + abs(store[i].y - y) <= 1000)
            {
                visited[i] = true;
                que.push({store[i].x, store[i].y});
            }
        }
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t(0);
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cin >> home.x >> home.y;
        for(int i = 0; i < n; i++)
            cin >> store[i].x >> store[i].y;
        cin >> festival.x >> festival.y;
        bool possible = BFS(n);
        if(possible == true)
            cout << "happy\n";
        else
            cout << "sad\n";
        memset(visited, false, sizeof(visited));
    }

    return 0;
}