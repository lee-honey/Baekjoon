#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A, B, C;
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    vec.emplace_back(A);
    vec.emplace_back(B);
    vec.emplace_back(C);

    sort(vec.begin(), vec.end());

    cout << vec[1] << '\n';

    return 0;
}