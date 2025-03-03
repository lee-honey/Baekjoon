#include <iostream>

using namespace std;

int N(0);

void Hanoi(int n, int from, int mid, int to)
{
    if(n == 1)
    {
        cout << from << " " << to << '\n';
        return; // 종료조건
    }
    Hanoi(n - 1, from, to, mid); // to를 보조로 사용 
    cout << from << " " << to << '\n'; //from에 있는 하나를 to로 이동
    Hanoi(n - 1, mid, from, to); // from을 보조로 사용
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int ans(0);
    ans = 2 << (N - 1);

    cout << ans - 1 <<'\n';
    Hanoi(N, 1, 2, 3);

    return 0;
}