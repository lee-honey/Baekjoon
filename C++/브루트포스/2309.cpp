#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[9] = {0,};
int sum(0);
int a(0), b(0);
vector<int> ans;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    bool quit(false);
    for(int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            int temp(0);
            temp = sum - arr[i] - arr[j];
            if(temp == 100)
            {
                for(int k = 0; k < 9; k++)
                {
                    if(k != i && k != j)
                        ans.push_back(arr[k]);
                }
                quit = true;
            }
            if(quit == true)
                break;
        }
        if(quit == true)
            break;
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < 7; i++)
        cout << ans[i] << '\n';

    return 0;
}