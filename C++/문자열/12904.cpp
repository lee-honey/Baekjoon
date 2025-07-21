#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S, T;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> T;

    while(1)
    {
        if(T[T.size() - 1] == 'A')
            T.pop_back();
        else if(T[T.size() - 1] == 'B')
        {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
        if(T.size() == S.size())
        {
            if(T == S)  cout << 1;
            else        cout << 0;
            break;
        }
    }

    return 0;
}