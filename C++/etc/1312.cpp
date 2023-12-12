#include <iostream>
using namespace std;

int main()
{
    int A, B, N, big_result;
    cin >> A >> B >> N;
    while (N--)
    {
        A = A % B;
        A = A * 10;
    }
    big_result = A / B;
    cout << big_result % 10 << '\n';
}
