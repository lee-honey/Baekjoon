#include <iostream>
#include <algorithm>
#define MAX 2147483647
#define MIN -2147483648
using namespace std;

int N(0);
int arr[101] = {0,};
int minAns(MAX), maxAns(MIN);
int oper[4] = {0,};

void BackTracking(int depth, int n)
{
    if(depth == N)
    {
        minAns = min(minAns, n);
        maxAns = max(maxAns, n);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int curN = n;
        if(oper[i] > 0)
        {
            switch(i)
            {
                case 0: curN += arr[depth]; break;
                case 1: curN -= arr[depth]; break;
                case 2: curN *= arr[depth]; break;
                case 3: curN /= arr[depth]; break;
            }

            oper[i]--;
            BackTracking(depth + 1, curN);
            oper[i]++;
        }

    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N;i++)
        cin >> arr[i];
    for(int i = 0; i < 4; i++)
        cin >> oper[i];

    BackTracking(1, arr[0]);

    cout << maxAns << '\n' << minAns << '\n';

    return 0;
}