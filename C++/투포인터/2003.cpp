#include <iostream>

using namespace std;

/* 투포인터
1. 처음 start, end인덱스는 0으로 같아야 함.
2. while문은 start <= end && end <=N 을 만족해야함
 (end <= N)인 이유: N에 도달하여야 배열에 빠져나가는 시점까지 파악 가능
3.각 반복마다 구해야 하는 값보다 크거나 같으면 st를, 작으면 et를 증가시켜주어야 함.
4.각 반복마다 배열에서 빼고 더하는 처리를 잘 해주어야 함. */

int main(void)
{
    int N(0), M(0), st(0), et(0), sum(0), answer(0);
    int A[10001] = {0,};
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    while(st <=et && et <= N)
    {
        if(sum >= M)
        {
            if(sum == M) answer++;
            sum -= A[st];
            st++;
        }
        else
        {
            sum += A[et];
            et++;
        }
    }

    cout << answer << endl;
}