#include <iostream>
#include <string>

using namespace std;

int M = 0;
int S[21] = {0, };

int main()
{    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;

    cin.ignore();

    while(M--)
    {
        string str = "";
        getline(cin, str);

        int iStrSize = 0;
        for(int i = 0; i < str.size(); i++)
            if(str[i] == ' ')
                iStrSize = i;
        string order = str.substr(0, iStrSize); // 명령
        string strNum = str.substr(iStrSize, str.size() - 1);
        int num = atoi(strNum.c_str());

        if(iStrSize == 0)
            order = str;

        if(order == "add")
        {
            if(S[num] == 0)
                S[num] = 1;
        }
        else if(order == "remove")
        {
            if(S[num] > 0)
                S[num] = 0;
        }
        else if(order == "check")
        {
            if(S[num] == 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(order == "toggle")
        {
            if(S[num] == 1)
                S[num] = 0;
            else
                S[num] = 1;
        }
        else if(order == "all")
        {
            for(int i = 0; i <= 20; i++)
                S[i] = 1;
        }
        else if(order == "empty")
        {
            for(int i = 0; i <= 20; i++)
                S[i] = 0;
        }
    }

    return 0;
}