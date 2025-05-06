#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> lst;
int N(0), M(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "";
    cin >> str;
    N = str.size();
    
    for(int i = 0; i < N; i++)
        lst.push_back(str[i]);

    auto cursor = lst.end();

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        char beh;
        cin >> beh;

        if(beh == 'L' && cursor != lst.begin())
            cursor--;
        else if(beh == 'D' && cursor != lst.end())
            cursor++;
        else if(beh == 'B' && cursor != lst.begin())
        {
            cursor--;
            cursor = lst.erase(cursor);
        }
        else if(beh == 'P')
        {
            char alp;
            cin >> alp;
            lst.insert(cursor, alp);
        }
    }

    for(auto iter : lst)
        cout << iter;
    cout << '\n';
    
    return 0;
}