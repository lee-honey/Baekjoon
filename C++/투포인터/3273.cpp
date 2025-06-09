#include <iostream>
#include <algorithm>

using namespace std;

int n(0);
int a[100001] = {0,};
int x(0);
int cnt(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;

    sort(a, a + n);

    int s(0), e(n - 1);

    while(s < e)
    {
        if(a[s] + a[e] >= x)
        {
            if(a[s] + a[e] == x)
                ++cnt;
            e--;
        }
        else
            s++;
    }

    cout << cnt << '\n';

    return 0;
}