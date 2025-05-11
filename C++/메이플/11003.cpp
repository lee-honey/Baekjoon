// 슬라이딩윈도우알고리즘문제 : 고정 사이즈의 윈도우가 이동하면서 윈도우 내에 있는 데이터를 이용해 문제를 풀이하는 알고리즘
// 투포인터는 넓이가 조건에따라 유동적으로 변하며, 슬라이딩은 구간의 넓이가 고정되어 있다는 차이
// 이동할 때마다 앞에있는값은 지우고, 다음값은 추가하면서 계산한다. (덱 사용)

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N(0), L(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    deque<pair<int, int>> dq;
    for(int i = 0; i < N; i++){ // Di의 인덱스값이 점차 늘어남 = 시작인덱스가 점차 커짐
        if(!dq.empty() && i == dq.front().second + L)        // 최소인덱스 갱신 필요
            dq.pop_front(); // 최솟값은 맨 앞에 있으므로 이 값을 뺄 것
        while(!dq.empty() && dq.back().first > arr[i]) // 최솟값이 될리 없는 값은 빼줌
            dq.pop_back();
        dq.push_back({arr[i], i});
        cout << dq.front().first << ' '; // 매번 i 갱신 시마다 최솟값 출력
    }
    
    return 0;
}