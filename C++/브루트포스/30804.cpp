#include <iostream>
#include <queue>
using namespace std;

int N = 0;
int cnt = 0, result = 0, len = 0;
int type[10];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--)
    {
        int num;
        cin >> num;
        q.push(num);
        len++;

        if(type[num] == 0)
            cnt++;
        type[num]++;

        while(cnt > 2)
        {
            int fruit = q.front();
            type[fruit]--;
            q.pop();
            len--;
            if(type[fruit] == 0)
                cnt--;
        }
        result = (result > len) ? result : len;
    }

    cout << result << '\n';

    return 0;
}