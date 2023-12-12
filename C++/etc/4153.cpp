#include <iostream>
#include <deque>
#include <stdio.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    deque<int> dq;
    int a[3] = { -1,-1,-1 };

    while (1)
    {
        int max = 0;
        cin >> a[0] >> a[1] >> a[2];
        if (a[0] == 0 && a[1] == 0 && a[2] == 0)
            break;
        for (int i = 0; i <= 2; i++)
        {
            if (a[i] >= max)
            {
                max = a[i];
                dq.push_back(a[i]);
            }
            else
                dq.push_front(a[i]);
        }
        if (dq[0] * dq[0] + dq[1] * dq[1] == dq[2] * dq[2])
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
        dq.clear();
    }
}