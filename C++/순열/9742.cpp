#include <iostream>
#include <cstring>

using namespace std;

string str;
int n(0);
char arr[11] = {0,};
bool bIsVisited[256] = {false,};
int cnt(0);
bool bCanMakeArr = false;

void DFS(char c, int depth)
{
    if(bCanMakeArr == true) return;

    if(depth == str.size())
    {
        if(++cnt == n)
        {
            cout << str << " " << n << " = ";
            for(int i = 0; i < str.size(); i++)
                cout << arr[i];
            cout << '\n';
            bCanMakeArr = true;
            return;
        }
    }

    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if(bIsVisited[ch] == false)
        {
            arr[depth] = ch;
            bIsVisited[ch] = true;
            DFS(i, depth + 1);
            bIsVisited[ch] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        cin >> str >> n;

        cnt = 0;
        memset(bIsVisited, false, sizeof(bIsVisited));
        memset(arr, 0, sizeof(arr));
        bCanMakeArr = false;

        if(cin.eof())
            break;
        
        DFS(0, 0);

        if(bCanMakeArr == false)
            cout << str << " " << n << " = No permutation\n";
    }

    return 0;
}