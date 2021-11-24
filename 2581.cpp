#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++) //소수를 이룰수있는 자연수들
        if (n % i == 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int M, N, sum = 0, min = 10000;
    cin >> M >> N;
    for (int i = M; i <= N; i++)
    {
        sum = (isPrime(i) == true) ? sum + i : sum;
        min = (isPrime(i) == true && min > i) ? i : min;
    }
    if (sum != 0)
    {
        cout << sum << '\n';
        cout << min << '\n';
    }
    else cout << -1 << '\n';
}