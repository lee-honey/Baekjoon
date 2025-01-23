#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int T(0), n(0);
string p = "";
deque<int> deq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        cin >> p;
        cin >> n;
        string str = "";
        cin >> str;
        int idx = 0;
        string temp = "";
        for(int i = 0; i < str.size(); i++)
        {
            if('0'<= str[i] && str[i] <= '9')
            {
                temp += str[i];
            }
            else if(temp != "")
            {
                deq.push_back(atoi(temp.c_str()));
                temp = "";
            }
        }

        bool bIsSwaped = false;
        bool bError = false;

        for(int i = 0; i < p.size(); i++)
        {
            if(p[i] == 'R')
            {
                bIsSwaped = !bIsSwaped;
            }
            else if(p[i] == 'D')
            {
                if(deq.empty())
                {
                    bError = true;
                }
                else
                {
                    if(bIsSwaped == false)
                        deq.pop_front();
                    else
                        deq.pop_back();
                }
            }
        }

        if(bError == true)
        {
            cout << "error" << '\n';
        }
        else
        {
            cout << '[';
            while(!deq.empty())
            {
                if(bIsSwaped == false)
                {
                    cout << deq.front();
                    deq.pop_front();
                }
                else
                {
                    cout << deq.back();
                    deq.pop_back();
                }
                if(!deq.empty())
                    cout << ',';
            }
            cout << ']' <<'\n';
        }
    }

    return 0;
}