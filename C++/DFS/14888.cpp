#include <iostream>
using namespace std;

int N(0);
int numArr[11] = {0,};
int operate[4] = {0,};
int minRes = 1000000001;
int maxRes = -1000000001;

void solve(int result, int idx)
{
    if(idx ==N)
    {
        if(maxRes < result)
            maxRes = result;
        if(minRes > result)
            minRes = result;
    }
    for(int i = 0; i < 4; i++)
    {
        if(operate[i] > 0)
        {
            operate[i]--;
            if(i == 0)solve(result + numArr[idx], idx + 1);
            if(i == 1)solve(result - numArr[idx], idx + 1);
            if(i == 2)solve(result * numArr[idx], idx + 1);
            if(i == 3)solve(result / numArr[idx], idx + 1);
            operate[i]++; //백트래킹
        }
    }
}

int main(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> numArr[i];
    }
    for(int i = 0; i < 4; i++)
    {
        cin >> operate[i];
    }
    solve(numArr[0],1);
    cout << maxRes << endl;
    cout << minRes << endl;
    return 0;
}