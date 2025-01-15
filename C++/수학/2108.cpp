#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int arr[500000] = {0, };
int num1[4001] = {0,};
int num2[4001] = {0,};
int iMax = -2147483648;
int iChoibinGap = 0;
vector<int> vecChoiBinGaps;
double fAverage = 0.0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        fAverage += arr[i];
        if(arr[i] >= 0)
            num1[arr[i]]++;
        else
            num2[arr[i] * -1]++;
    }

    sort(arr, arr + N);

    if(-1 < fAverage / N && fAverage / N < 0)
        cout << 0 << endl;
    else
        cout << round(fAverage / N) << endl;      // 산술평균
    cout << arr[(N - 1) / 2] << endl;             // 중앙값

    for(int i = 1; i < 4001; i++)
    {
        if(iMax < num2[i])
            iMax = num2[i];
    }
    for(int i = 0; i < 4001; i++)
    {
        if(iMax < num1[i])
            iMax = num1[i];
    }

    for(int i = 4000; i >= 1; i--)
    {
        if(num2[i] == iMax)
            vecChoiBinGaps.push_back(-i);
    }

    for(int i = 0; i < 4001; i++)
    {
        if(num1[i] == iMax)
            vecChoiBinGaps.push_back(i);
    }

    if(vecChoiBinGaps.size() == 1)
        cout << vecChoiBinGaps[0] << endl;
    else
        cout << vecChoiBinGaps[1] << endl;  // 최빈값

    cout << arr[N - 1] - arr[0] << endl;    // 범위
    
    return 0;
}