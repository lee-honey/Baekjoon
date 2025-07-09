#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
char arr[51][51];

int getMax() {
    int maxCount = 1;

    for (int i = 0; i < N; i++) {
        int rowCount = 1;
        for (int j = 1; j < N; j++) {
            if (arr[i][j] == arr[i][j - 1]) rowCount++;
            else rowCount = 1;
            maxCount = max(maxCount, rowCount);
        }

        int colCount = 1;
        for (int j = 1; j < N; j++) {
            if (arr[j][i] == arr[j - 1][i]) colCount++;
            else colCount = 1;
            maxCount = max(maxCount, colCount);
        }
    }

    return maxCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
            arr[i][j] = str[j];
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j + 1 < N && arr[i][j] != arr[i][j + 1])
            {
                swap(arr[i][j], arr[i][j + 1]);
                ans = max(ans, getMax());
                swap(arr[i][j], arr[i][j + 1]);
            }

            if (i + 1 < N && arr[i][j] != arr[i + 1][j])
            {
                swap(arr[i][j], arr[i + 1][j]);
                ans = max(ans, getMax());
                swap(arr[i][j], arr[i + 1][j]); // 복구
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
