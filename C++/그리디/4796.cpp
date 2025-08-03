#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int idx(1);
    int L, P, V;
    while(1)
    {
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0)
            break;
        int ans = L * (V / P);
        V -= P * (V / P);
        int add = (L < V) ? L : V;
        ans += add;
        
        cout << "Case " << idx++ <<": " << ans << '\n';
    }

    return 0;
}