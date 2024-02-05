#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    int N(0), lt(0), rt(0), _min(0), ans[2] = {0,};
    cin >> N;
     int arr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    rt = N - 1;
    _min = abs(arr[lt] + arr[rt]);
    ans[0] = arr[lt];
    ans[1] = arr[rt];
    while(lt + 1< rt)
    {
        if(abs(arr[lt + 1] + arr[rt]) <= abs(arr[lt] + arr[rt - 1]))
        {
            if(abs(arr[lt + 1] + arr[rt]) < _min)
            {
                _min = abs(arr[lt + 1] + arr[rt]);
                ans[0] = arr[lt + 1];
                ans[1] = arr[rt];
                if(_min == 0)
                    break;
            }
            lt++;
        }
        else
        {
            if(abs(arr[lt] + arr[rt - 1]) < _min)
            {
                _min = abs(arr[lt] + arr[rt - 1]);
                ans[0] = arr[lt];
                ans[1] = arr[rt - 1];
                if(_min == 0)
                    break;
            }
            rt--;
        }
    }
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}