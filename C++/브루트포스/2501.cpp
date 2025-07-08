#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N(0), K(0);
deque<int> yaksu;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i < N; i++)
    {
        if(N % i == 0)
        {
            if(i > N / i)
                break;
            yaksu.push_front(i);
            if(i != N / i)
                yaksu.push_back(N / i);
        }
    }

    sort(yaksu.begin(), yaksu.end());

    if(yaksu.size() < K)
        cout << "0" << '\n';
    else
        cout << yaksu[K - 1] << '\n';

    return 0;
}