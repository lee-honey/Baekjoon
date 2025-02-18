#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];  // 방문 여부 체크
int fast(2047483647), ans(0);
queue<pair<int, int>> que;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    que.push({N, 0});
    
    while (!que.empty()) {
        int cur = que.front().first;
        int time = que.front().second;
        que.pop();

        visited[cur] = true;

        if(fast < time) continue;
        
        if (cur == K) { //너비우선탐색 규칙..랄까.
            fast = time;
            ans++;
            continue;
        }

        if(0 <= cur - 1 && !visited[cur - 1])
            que.push({cur - 1, time + 1});
        if(cur + 1 <= 100000 && !visited[cur + 1])
            que.push({cur + 1, time + 1});
        if(cur * 2 <= 100000 && !visited[cur * 2])
            que.push({cur * 2, time + 1});
    }

    cout << fast << '\n' << ans << '\n';
    return 0;
}
