#include <iostream>
#include <string>

using namespace std;

string X;
int cnt(0);
int num(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X;

    while(1)
    {
        num = 0;
        ++cnt;
        for(int i = 0; i < X.size(); i++)
        {
            num += (X[i]) - '0';
        }

        if(0 <= num && num <= 9)
        {
            if(cnt == 1 && X.size() == 1)
                cnt = 0;
            break;
        }
        else
            X = to_string(num);
    }

    cout << cnt << '\n';
    if(num % 3 == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}