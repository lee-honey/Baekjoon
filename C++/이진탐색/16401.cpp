#include <iostream>
#include <algorithm>
using namespace std;

int DivideSnack(int mid,int N, int Arr[])
{
    int cnt(0);
    for (int i = 0; i < N; i++)
        cnt += Arr[i] / mid;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int M(0), N(0), lt(0), rt(0), mid(0), result(0);
    cin >> M >> N;
    int Arr[N] = {0,};
    for (int i = 0; i < N; i++)
        cin >> Arr[i];
    sort(Arr, Arr + N);
    lt = 1;
    rt = *max_element(Arr, Arr + N);
    while (lt <= rt)
    {
        mid = (lt + rt) / 2;
        if(M <= DivideSnack(mid, N, Arr))
        {
            lt = mid + 1;
            result = mid;
        }
        else
            rt = mid - 1;
    }
    cout << result << endl;
}