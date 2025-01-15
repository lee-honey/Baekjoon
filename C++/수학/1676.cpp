#include <iostream>

using namespace std;

int N = 0, result = 1, cnt = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    while(N > 0)
    {
        result *= N;

        if(N % 125 == 0)
            cnt += 3;
        else if(N % 25 == 0)
            cnt += 2;
        else if(N % 5 == 0)
            cnt += 1;

        N--;


    cout << cnt << endl;

    return 0;
}