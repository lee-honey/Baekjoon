#include <iostream>

using namespace std;

int     N(0);
int     arr[11] = {0,};
bool    bIsVisited[10] = {false,};

void BackTracking(int depth)
{
    
    for(int i = 0; i <= 9; i++)
    {
        bIsVisited[i] = true;
        BackTracking(depth );
        bIsVisited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < 9; i++)
    {
        BackTracking(i);
    }

    return 0;
}

