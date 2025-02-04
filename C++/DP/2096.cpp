#include <iostream>

using namespace std;

int N(0);
int arr[100000][3];
int DPMax[3], DPMin[3];

int Max(int a, int b){return (a > b) ? a : b;}
int Min(int a, int b){return (a < b) ? a : b;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int maxA(DPMax[0]), maxB(DPMax[1]), maxC(DPMax[2]);
        int minA(DPMin[0]), minB(DPMin[1]), minC(DPMin[2]);

        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            if(i == 0)
            {
                DPMax[j] = arr[i][j];
                DPMin[j] = arr[i][j];
            }
            else
            {
                if(j == 0)
                {
                    DPMax[j] = Max(maxA, maxB) + arr[i][j];
                    DPMin[j] = Min(minA, minB) + arr[i][j];
                }
                else if(j == 1)
                {
                    DPMax[j] = Max(maxA,Max(maxB, maxC)) + arr[i][j];
                    DPMin[j] = Min(minA,Min(minB, minC)) + arr[i][j];
                }
                else if(j == 2)
                {
                    DPMax[j] = Max(maxB, maxC) + arr[i][j];
                    DPMin[j] = Min(minB, minC) + arr[i][j];
                }
            }
        }
    }

    cout << Max(DPMax[0], Max(DPMax[1], DPMax[2])) << " "
    << Min(DPMin[0], Min(DPMin[1], DPMin[2]));

    return 0;
}