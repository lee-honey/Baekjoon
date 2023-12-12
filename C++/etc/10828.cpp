#include<iostream>
#include<stack>
#include<string>
 
using namespace std;
 
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    stack<int> st;
    string com;

    cin >> N;
    while(N--)
    {
        cin >> com;
        if(com == "push")
        {
            int n;
            cin >> n;
            st.push(n);
        }
        if(com == "top")
        {
            if(st.size() == 0)
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
        if (com == "size")
            cout << st.size() << '\n';
        if(com == "pop")
        {
            if(st.size() == 0)
                cout << -1 << '\n';
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        if(com == "empty")
            cout << (st.empty()? 1 : 0) << '\n';
    }
    return 0;
}
