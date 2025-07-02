#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N(0), M(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<int> v(N, 0);
    
    for(int i = 0; i < M; i++)
    {
        int num(0), train(0), x(0);
        cin >> num >> train;

        train -= 1;

        if(num == 1 || num == 2){
            cin >> x;

            x -= 1;
        }

        if(num == 1)
            v[train] |= (1 << x);
        if(num == 2)
            v[train] &= ~(1 << x);
        if(num == 3)
        {
            v[train] <<= 1;
            v[train] &= ((1 << 20) - 1);
        }
        if(num == 4)
            v[train] >>= 1;
    }

    set<int> st;
    for(int i = 0; i < v.size(); i++)
        st.insert(v[i]);

    cout << st.size() << '\n';

    return 0;
}