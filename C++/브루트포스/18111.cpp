#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0, B = 0;
int arr[500][500] = {0, };
vector<int> temp;
int iMin = 2147483647, iMax = -2147483648;
int iHeight = -1, iTime = 2147483647;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            temp.push_back(arr[i][j]);
            iMax = (arr[i][j] > iMax) ? arr[i][j] : iMax;
            iMin = (arr[i][j] < iMin) ? arr[i][j] : iMin;
        }
    }

    sort(temp.begin(), temp.end());

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            arr[i][j] = temp[temp.size() - 1];
            temp.pop_back();
        }
    }

    for(int h = iMin; h <= iMax; h++)
    {
        int iTempTime = 0, iTempB = B, bCanPush = true;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(arr[i][j] < h)
                {
                    if(iTempB - ((h - arr[i][j])) >= 0)
                    {
                        iTempTime += (h - arr[i][j]) * 1;
                        iTempB -= (h - arr[i][j]);
                    }
                    else
                        bCanPush = false;
                }
                else if(arr[i][j] > h)
                {
                    iTempTime += (arr[i][j] - h) * 2;
                    iTempB += (arr[i][j] - h);
                }
            }
        }

        if(iTempB >= 0 && iTempTime <= iTime && bCanPush == true)
        {
            iTime = iTempTime;
            iHeight = h;
        }
    }

    cout << iTime << " " << iHeight << '\n';

    return 0;
}