#include <iostream>
#include <queue>

using namespace std;

int N = 0, M = 0, iCount = 0;
char arr[600][600];
bool bVisited[600][600] = {false,};
pair<int, int> iPos;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS()
{
    queue<pair<int, int>> q;
    q.push(iPos);
    bVisited[iPos.first][iPos.second] = true;

    while(!q.empty())
    {
        pair<int, int> iCur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            pair<int, int> iNext = {iCur.first + dy[i] , iCur.second + dx[i] };

            if(iNext.first < 0 || iNext.first >= N ||
            iNext.second < 0 || iNext.second >= M)
                continue;
            if(arr[iNext.first][iNext.second] == 'X')
                continue;
            if(bVisited[iNext.first][iNext.second] == true)
                continue;
            
            if(arr[iNext.first][iNext.second] == 'P')
                iCount++;

            q.push(iNext);
            bVisited[iNext.first][iNext.second] = true;
        }
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
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'I')
                iPos = {i, j};
        }
    }

    BFS();

    if(iCount == 0)
        cout << "TT" << '\n';
    else
        cout << iCount << '\n';

    return 0;
}