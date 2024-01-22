#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main (void)
{
    int N(0), st(0), ed(0), min(1000000000), lt(0), rt(0);
    cin >> N;
    ed = N - 1;
    rt = N - 1;
    int arr[N] = {0,};
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    min = abs(arr[st] + arr[ed]);
    while(st <= ed)
    {
        if(st + 1 == ed || st == ed - 1)
            break;
        if (abs(arr[st + 1] + arr[ed]) > abs(arr[st] + arr[ed - 1]))
        {
            if(abs(arr[st] + arr[ed - 1]) < min)
            {
                min = abs(arr[st] + arr[ed - 1]);
                lt = st;
                rt = ed - 1;
            }
            ed--;
        }
        else
        {
            if(abs(arr[st + 1] + arr[ed]) < min)
            {
                min = abs(arr[st + 1] + arr[ed]);
                lt = st + 1;
                rt = ed;
            }
            st++;
        }
    }
    cout << arr[lt] << " " << arr[rt] << endl;
    return 0;
}