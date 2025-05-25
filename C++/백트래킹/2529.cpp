#include <iostream>
#include <string>
using namespace std;

int k;
char arr[10];
bool bIsVisited[10] = {false,};
int myNum[10] = {0,};
string strMin, strMax;

void DFS(int depth)
{
    if(depth == k + 1)
    {
        string str;
        for(int i = 0; i <= k; i++)
            str += myNum[i] + '0';

        if(strMin.empty() || str < strMin)
            strMin = str;
        if(strMax.empty() || str > strMax)
            strMax = str;

        return;
    }

    int st(0), ed(9);
    if(depth > 0)
    {
        char c = arr[depth - 1];
        if(c == '<'){   st =  myNum[depth - 1] + 1; ed = 9; }
        else if(c == '>'){  st = 0; ed = myNum[depth - 1] - 1;}
    }
    for(int i = st; i <= ed; i++)
    {
        if(bIsVisited[i] == false)
        {
            bIsVisited[i] = true;
            myNum[depth] = i;
            DFS(depth + 1);
            bIsVisited[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> arr[i];

    DFS(0);

    cout << strMax << '\n';
    cout << strMin << '\n';

    return 0;
}
