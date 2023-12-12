#include <iostream>
using namespace std;

int main()
{
    int N;
    double a[10000], max, base;
    cin >> N;
    max = 0.0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        base = a[i];
        for (int j = i + 1; j < N; j++)
        {
            base = base * a[j];
            if (base > max)
                max = base;
        }
    }
    cout << fixed;
    cout.precision(3);
    cout << max << '\n';
}
