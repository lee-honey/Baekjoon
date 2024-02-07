#include <iostream>
#include <queue>

using namespace std;

int N(0), K(0), ans(0), depth(0);
queue<pair<int, int>> q;
bool isVisited[100001] = {false,};

int main(void)
{
    cin >> N >> K;
    q.push({N,depth});
    while(!q.empty())
    {

        int temp = q.front().first;
        int tempDep = q.front().second;
        isVisited[temp] = true;
        q.pop();
        if(temp == K)
        {
            cout << tempDep << endl;
            break;
        }
        if(depth == tempDep)//깊이 갱신
            depth = depth + 1;
        if(temp - 1 >= 0 && isVisited[temp - 1] == false) q.push({temp - 1, depth});
        if(temp + 1 <= 100000 && isVisited[temp + 1] == false) q.push({temp + 1, depth});
        if(temp * 2 <= 100000 && isVisited[temp * 2] == false) q.push({temp * 2, depth});
    }
    return 0;
}