#include <iostream>
#include <queue>
using namespace std;

int T(0), A(0), B(0);
string dslr[4] = {"D", "S", "L", "R"};

int MakeN(int n, int idx)
{
    if(idx == 0)
        return (2 * n) % 10000;
    else if(idx == 1)
        return (n - 1 == 0) ? 9999 : n - 1;
    else if(idx == 2)
        return n * 10 - ((n * 10) / 10000) * 10000 + ((n * 10) / 10000);
    else if(idx == 3)
        return (n % 10) * 1000 + (n / 10);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        queue<pair<int, string>> que;
        bool bVisited[10000] = {false,};
        cin >> A >> B;

        que.push({A , ""});
        bVisited[A] = true;
        
        while(!que.empty())
        {
            pair<int, string> cur = que.front();
            que.pop();

            if(cur.first == B)
            {
                cout << cur.second <<'\n';
                break;
            }
            
            for(int i = 0; i < 4; i++)
            {
                int n = MakeN(cur.first, i);
                string str = cur.second;
                if(!bVisited[n])
                {
                    str += dslr[i];
                    que.push({n, str});
                    bVisited[n] = true;
                }
            }
        }
    }

    return 0;
}