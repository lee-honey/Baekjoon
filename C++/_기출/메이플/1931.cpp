// 회의실 배정 문제: 그리디 알고리즘 적용

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N(0);
vector<pair<int, int>> vec;
int ans(0);
int tm(0);

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int begin(0), end(0);
        cin >> begin >> end;
        vec.push_back({begin, end});
    }

    sort(vec.begin(), vec.end()); // 시작시간기준정렬
    sort(vec.begin(), vec.end(), compare); // 종료시간기준 오름차순 정렬

    tm = vec[0].second;
    ans = 1;
    for(int i = 1; i < N; i++)
    {
        if(tm <= vec[i].first)
        {
            tm = vec[i].second;
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}