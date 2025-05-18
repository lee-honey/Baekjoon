#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        string str = "";
        getline(cin, str);

        if(str == ".")
            break;

        int i = 0;
        while(str[i] != '.')
        {
            if(str[i] == '(' || str[i] == '[')
                arr.push(str[i]);

            else if((!arr.empty() && arr.top() == '(' && str[i] == ')')
            || (!arr.empty() && arr.top() == '[' && str[i] == ']'))
                arr.pop();
            
            else if(str[i] == ')' || str[i] == ']')
                arr.push(str[i]);
            
            i++;
        }

        if(arr.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        while(!arr.empty())
        {
            arr.pop();
        }
    }

    return 0;
}