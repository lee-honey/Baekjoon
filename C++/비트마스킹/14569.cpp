#include <iostream>
#include <vector>

using namespace std;

int N(0), M(0);
vector<unsigned long long> t, q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    t.resize(N);
    for(int i = 0; i < N; i++)
    {
        int K(0);
        cin >> K;
        for(int j = 0; j < K; j++)
        {
            int ti;
            cin >> ti;
            t[i] |= (1ll << ti);
        }
    }
    cin >> M;
    q.resize(M);
    for(int i = 0; i < M; i++)
    {
        int P(0);
        cin >> P;
        for(int j = 0; j < P; j++)
        {
            int qi;
            cin >> qi;
            q[i] |= (1ll << qi);
        }
    }

    for(int i = 0; i < M; i++)
    {
        int cnt(0);
        for(int j = 0; j < N; j++)
        {
            if(t[j] == (t[j] & q[i])) // t와 q가 겹치는 부분이 t와 같을때 t가 완전히 포함된다고 봄
                cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}