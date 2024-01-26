#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<char> passwd;
int L(0), C(0);
void DFS(char arr[], int start, int depth)
{
    if(depth == L)
    {
        int cntI(0), cntC(0);
        for(int i = 0; i < L; i++) //범위를 정확히 설정해줘야...
        {
            if(passwd[i] == 'a' || passwd[i] == 'e' || passwd[i] == 'i'
            || passwd[i] == 'o' || passwd[i] == 'u')
                cntI++;
            else
                cntC++;
        }
        if(cntI >= 1 && cntC >= 2)
        {
            for(int i = 0; i < L; i++)
                cout << passwd[i];
            cout << endl;
        }
        return;
    }
    for(int i = start; i < C; i++)
    {
        passwd.push_back(arr[i]);
        DFS(arr, i + 1, depth + 1); //재귀 들어가기 전에 push, 들어오고 나서 pop
        passwd.pop_back();
    }
    return;
}

int main(void)
{
    cin >> L >> C;
    char arr[C] = {0,};
    for(int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + C);
    DFS(arr, 0,0);
    return 0;
}