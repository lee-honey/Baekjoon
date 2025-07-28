#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[3];
vector<int> vec(3);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 3; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    for(int i = 0; i < 3; i++)
        cout << vec[i] << " ";

    return 0;
}