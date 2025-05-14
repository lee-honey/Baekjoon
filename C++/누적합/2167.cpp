#include <iostream>
using namespace std;

int N, M, K, ans;
int arr[301][301];
int prefix[301][301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];

    cin >> K;
    while(K--)
    {
        int i(0), j(0), x(0), y(0);
        cin >> i >> j >> x >> y;
        cout << prefix[x][y] - prefix[i - 1][y] - prefix[x][j - 1] + prefix[i - 1][j - 1] << '\n';
    }
    return 0;
}
