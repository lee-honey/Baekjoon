#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N(0), M(0);
vector<pair<int, int>> A, B;
vector<int> ans;

bool cmp(pair<int, int> a, pair<int, int>b)
{
	if (a.first == b.first) return a.second < b.second; //이게 있어야 같은숫자 여러개가 있어도 순서대로 참조 가능임
    return a.first > b.first;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int iNum(0);
        cin >> iNum;
        A.push_back({iNum, i});
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int iNum(0);
        cin >> iNum;
        B.push_back({iNum, i});
    }

    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);

    int idxA(0), idxB(0), maxA(0), maxB(0);
    while(idxA < N && idxB < M)
    {
        if(A[idxA].first == B[idxB].first)
        {
            if(maxA > A[idxA].second)
                idxA++;
            else if(maxB > B[idxB].second)
                idxB++;
            else
            {
                maxA = A[idxA].second;
                maxB = B[idxB].second;
                ans.push_back(A[idxA].first);
                idxA++;
                idxB++;
            }
        }
        else if(A[idxA].first > B[idxB].first)
            idxA++;
        else
            idxB++;
    }

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
