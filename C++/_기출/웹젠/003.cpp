#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 올라가는 수 최대 개수: 2^10 - 1 = 1023
    if (N > 1023) {
        cout << -1 << "\n";
        return 0;
    }

    vector<string> arr;
    // 1자리 수: "0"부터 "9"
    for (int i = 0; i <= 9; i++) {
        arr.push_back(string(1, '0' + i));
    }

    for (int i = 0; i < (int)arr.size(); i++) {
        string curr = arr[i];
        char last_digit = curr.back();

        for (char c = last_digit + 1; c <= '9'; c++) {
            if ((int)arr.size() >= 1023) break;
            arr.push_back(curr + c);
        }
    }

    cout << arr[N - 1] << "\n";

    return 0;
}
