// 백준 1395 스위치
// 세그먼트 트리: 값의 범위가 큰 경우 구간합을 구할 때 유용한 알고리즘
// 일괄적인 값에 대한 변경 처리가 일어나야 할 경우 lazy Propagation이 필요
// lazy Propagation: 업데이트를 최대한 미루는 방식
// 이건 걍 전체적으로 흐름을 외우는게 좋을 것
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N(0), M(0);
vector<pair<int, pair<int, int>>> cmd;
vector<int> segTree; // 켜지면 1로 바뀜
vector<int> lazy;

void Lazy_Update(int node, int start, int end)
{
    if(lazy[node] != 0)
    {
        segTree[node] = (end - start + 1) - segTree[node];
        if(start != end)
        {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        lazy[node] = 0; // 초기화
    }
}

void Update(int node, int start, int end, int left, int right)
{
    Lazy_Update(node, start, end); // 레이지 처리 먼저
    if(right < start || left > end) return; // 1. 아예 구간이 속하지 않을경우 건너뜀
    if(left <= start && end <= right) // 2. 구간 전체가 속하는 경우
    {
        segTree[node] = (end - start + 1) - segTree[node]; // 켜진개수 = 전체 길이 - 기존 켜진 개수
        if(start != end)
        {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        return;
    } // 일부만 걸쳐있는 경우
    int mid = (start + end) / 2;
    Update(node * 2, start, mid, left, right);
    Update(node * 2 + 1, mid + 1, end, left, right);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

int Query(int node, int start, int end, int left, int right)
{
    Lazy_Update(node, start, end);
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return segTree[node];
    int mid = (start + end) / 2;
    int lRes = Query(node * 2, start, mid, left, right);
    int rRes = Query(node * 2 + 1, mid + 1, end, left, right);
    return lRes + rRes;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cmd.push_back({a, {b, c}});
    }
    int tHeight = (int)ceil(log2(N));
    int tSize = 1 << (tHeight + 1);
    segTree. resize(tSize, 0);      // 세그트리만듦
    lazy.resize(tSize);             // 같은사이즈로 레이지트리도 만듦
    for(int i = 0; i < M; i++)
    {
        int command(cmd[i].first);
        int idx(cmd[i].second.first - 1);
        int idx2(cmd[i].second.second - 1); 
        if(command == 0) // 코멘드 들어올때마다
        {
            Update(1, 0, N - 1, idx, idx2); // 구간합 업데이트
            continue;
        }
        else if(command == 1) // 출력
            cout << Query(1, 0, N - 1, idx, idx2) << '\n';
    }

    return 0;
}