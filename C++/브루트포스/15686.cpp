#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0), M(0), ans(2147483647);
int cities[51][51];

vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> points;

int calc()
{
    int sum = 0;

    for(int i = 0; i < home.size(); i++)
    {
        int Min = 2147483647;
        for(int j = 0; j < points.size(); j++)
        {
            int x = abs(points[j].first - home[i].first);
            int y = abs(points[j].second - home[i].second);
            Min = min(Min, x + y);
        }

        sum += Min;
    }

    return sum;
}

void DFS(int idx)
{
    if(points.size() == M)
    {
        ans = min(ans, calc());
        return;
    }

    for(int i = idx; i < chicken.size(); i++)
    {
        points.push_back(chicken[i]);
        DFS(i + 1);
        points.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> cities[i][j];

            if(cities[i][j] == 2)
                chicken.push_back({i, j});
            else if(cities[i][j] == 1)
                home.push_back({i, j});
        }
    }

    DFS(0);

    cout << ans << '\n';

    return 0;
}