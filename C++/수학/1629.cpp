#include <iostream>

using namespace std;

long long A = 0, B = 0, C = 0;

long long MyHamsu(long long A, long long B, long long C)
{
    if(B == 0)
        return 1;

    long long temp = MyHamsu(A, B / 2, C);
    temp = temp * temp % C;
    if(B % 2 == 0) return temp;
    else return A * temp % C;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> A >> B >> C;
    cout << MyHamsu(A, B, C) << '\n';

    return 0;
}