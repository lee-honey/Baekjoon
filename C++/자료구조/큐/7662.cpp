#include <iostream>
#include <set>

using namespace std;

int T(0), k(0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        multiset<int> st;
        cin >> k;
        while(k--)
        {
            char c; int i(0);
            cin >> c >> i;
            if(c == 'I')
            {
                st.insert(i);
            }
            else if(c == 'D' && !st.empty())
            {
                if(i == -1)
                    st.erase(st.begin());
                else
                    st.erase(--st.end());
            }
        }

        if(st.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *(--st.end()) << " " << *(st.begin()) << '\n';
    }

    return 0;
}