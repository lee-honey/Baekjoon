// 분할정복이용

#include <iostream>
#include <map>
#define MOD 1000000007

using namespace std;

long long n(0);
map<long long, long long> mp; // 이미 구한 피보나치는 DP 처럼 저장해야함

long long Fibonacci(long long n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    if (mp.find(n) != mp.end())
        return mp[n];

    if(n % 2 == 0)
    {
        mp[n] = (Fibonacci(n / 2) * (2 *  Fibonacci(n / 2 - 1) + Fibonacci(n / 2))) % MOD;
        return mp[n];
    }
    else
    {
        mp[n] = (Fibonacci((n + 1) / 2) * Fibonacci((n + 1) / 2) 
        + Fibonacci((n - 1) / 2) * Fibonacci((n - 1) / 2)) % MOD;
        return mp[n];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout << Fibonacci(n);

    return 0;
}