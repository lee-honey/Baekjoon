#include <iostream>
#include <stack>
using namespace std;

string str = "";
string realStr = "";
stack<char> st;
int answer(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for(int i = 0; i < str.size() - 1; i++)
    {
        if(str[i] == '(' && str[i + 1] == ')')
        {
            str[i] = '|';
            str[i + 1] = '|';
        }
    }

    for(int i = 0; i < str.size(); i++)
    {
        realStr += str[i];
        if(str[i] == '|')   i++;
    }

    for(int i = 0; i < realStr.size(); i++)
    {
        if(realStr[i] == '|')
        {
            answer += st.size();
        }
        else if(realStr[i] == '(')
        {
            st.push('(');
        }
        else if(realStr[i] == ')')
        {
            st.pop();
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}