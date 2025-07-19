#include <iostream>

// 가장 작은 자릿수부터 그 자릿수에 해당하는 모든 수를 오름차순으로 탐색 후,
// 다음 자리수에 해당하는 모든 수를 오름차순으로 탐색
// 감소하는 수는 유한하다.

using namespace std;

int N(0), cnt(0);
long long ans(-1);

void BackTracking(long long num, int size)
{
    if(size == 0)
    {
        if(cnt == N)
            ans = num;
        cnt++;
        return;
    }
    int last = num % 10;
    if(num == 0)
        last = 10;
    for(int i = 0; i < last; i++)
    {
        long long nextNum = (num * 10) + i;
        if(num == 0 && i == 0) continue;

        BackTracking(nextNum, size - 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i = 0; i <= 10; i++)
        BackTracking(0, i);
        
    cout << ans << '\n';

    return 0;
}