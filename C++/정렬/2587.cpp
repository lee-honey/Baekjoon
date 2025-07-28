#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec(5);
int sum(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 5; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }

    sort(vec.begin(), vec.end());

    cout << sum / 5 << '\n';
    cout << vec[2] << '\n';

    return 0;
}