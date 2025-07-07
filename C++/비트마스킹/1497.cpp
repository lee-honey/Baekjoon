#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int             N(0), M(0);
long long       guitar[11] = {0,};
int             ans(INT_MAX);
int             maxCnt(0);

int countBit(long long bit){
    int cnt(0);
    while(bit){
        cnt += bit & 1;
        bit >>= 1;
    }
    return cnt;
}

void BackTracking(int depth, long long bit, int cnt)
{
    int bitToSong = countBit(bit);

    if(bitToSong > maxCnt)
    {
        maxCnt = bitToSong;
        ans = cnt;
    }
    else if(bitToSong == maxCnt)
        ans = min(ans, cnt);

    if(depth == N) return;

    BackTracking(depth + 1, bit | guitar[depth], cnt + 1); // 선택을 함
    BackTracking(depth + 1, bit, cnt); // 선택을 하지 않음
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        string str, canPlay;
        cin >> str >> canPlay;
        for(int j = 0; j < M; j++){
            if(canPlay[j] == 'Y')
                guitar[i] |= (1LL << (M - 1 - j));
        }
    }

    BackTracking(0, 0, 0);

    if(!maxCnt)
        cout << "-1" << '\n';
    else
        cout << ans << '\n';

    return 0;
}