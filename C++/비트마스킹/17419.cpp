#include <iostream>
#include <string>

using namespace std;

int     N(0), numK(0), ans(0);
string  K;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i < K.size(); i++)
        if(K[i] == '1')
            ans++;
            
    cout << ans << '\n';

    return 0;
}