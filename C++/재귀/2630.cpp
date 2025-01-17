#include <iostream>

using namespace std;

int N = 0, iBlue = 0, iWhite = 0;
int arr[128][128] = {0, };

void Jaegui(int x, int y, int N)
{
    bool bCut = false;
    int iColor = arr[x][y];
    for(int i = x; i < x + N; i++)
    {
        for(int j = y; j < y + N; j++)
        {
            if(arr[i][j] != iColor)
                bCut = true;
        }
    }

    if(bCut == true)
    {
        Jaegui(x, y, N / 2);
        Jaegui(x, y + N / 2, N / 2);
        Jaegui(x + N / 2, y, N / 2);
        Jaegui(x + N / 2, y + N / 2, N / 2);
    }
    else
    {
        if(iColor == 1)
            iBlue++;
        else
            iWhite++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    Jaegui(0, 0, N);

    cout << iWhite << '\n';
    cout << iBlue << '\n';

    return 0;
}