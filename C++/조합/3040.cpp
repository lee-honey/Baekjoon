#include <iostream>

using namespace std;

int sum(0);
int total(100);
int dwarf[9] = {0,};
int arr[7] = {0,};
void DFS(int depth, int start)
{
    if(depth == 7)
    {
        int sum = 0;
        for(int i = 0; i < 7; i++)
            sum += arr[i];
        if(sum == 100)
            for(int i = 0; i < 7; i++)
                cout << arr[i] << '\n';
        return;
    }
    for(int i = start; i < 9; i++)
    {
        arr[depth] = dwarf[i];
        DFS(depth + 1, i + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 9; i++)
        cin >> dwarf[i];
    DFS(0, 0);
    
    return 0;
}