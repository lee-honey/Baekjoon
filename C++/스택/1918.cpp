#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str = "";
char arr[101];
stack<char> st;
string res = "";

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for(int i = 0; i < str.size(); i++)
        arr[i] = str[i];
    
    for(int i = 0; i < str.size(); i++)
    {
        if('A' <= arr[i] && arr[i] <= 'Z')
            res += arr[i];
        else if(arr[i] == '(') // 이렇게 우선순위가 있음
            st.push(arr[i]);
        else if(arr[i] == '*' || arr[i] == '/')
        {
            while(!st.empty() && (st.top() == '*' || st.top() == '/'))
            {
                res += st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        else if(arr[i] == '+' || arr[i] == '-')
        {
            while(!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        else if(arr[i] == ')')
        {
            while(!st.empty()  && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
    }

    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }

    cout << res << '\n';

    return 0;
}