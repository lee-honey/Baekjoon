#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> ans;

vector<int> sortBinaryNumbers(vector<vector<int>> bitArrays)
{
    for (auto& arr : bitArrays) {
        sort(arr.begin(), arr.end(), greater<>()); // 역순 정렬
    }

    auto cmp = [&](int a, int b) {
        const auto& A = bitArrays[a];
        const auto& B = bitArrays[b];
        return A < B; // B의 우선순위가 크면 B가 앞에 옴(우선순위큐는 소트와 반대)
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < bitArrays.size(); i++) {
        pq.push(i); // 각 비트어레이를 순회하며 그 인덱스를 cmp기준으로 저장
    }

    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> vec = {{0, 1 , 2}, {3, 1, 0}};
    sortBinaryNumbers(vec);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    
    return 0;
}