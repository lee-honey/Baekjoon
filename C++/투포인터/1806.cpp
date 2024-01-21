#include <iostream>

using namespace std;

int main(void)
{
    int N(0), S(0), st(0), ed(0);
    int tempLen(0), minLen(100000), sum(0);
    int A[100000] = {0,};
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    while (st <= ed && ed <= N)
    {
        if(sum >= S)
        {
            if (minLen > tempLen)
                minLen = tempLen;
            sum -= A[st];
            tempLen--;
            st++;
        }
        else
        {
            sum += A[ed];
            tempLen++;
            ed++;
        }
    }
    if (minLen != 100000)
        cout << minLen << endl;
    else
        cout << "0" << endl;
    return 0;
}