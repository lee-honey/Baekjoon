#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int MaxWeight(0);
    int itemCount(0);

    cin >> MaxWeight >> itemCount;

    vector<int> itemWeight(itemCount);
    vector<int> itemPrice(itemCount);

    for(int i = 0; i < itemCount; i++)
    {
        cin >> itemWeight[i] >> itemPrice[i];
    }

    vector<int> DP(MaxWeight + 1, 0);

    int totalPrice = 0;

    for(int i = 0; i < itemCount; i++)
    {
        for(int j = MaxWeight; j >=itemWeight[i]; j--)
        {
            DP[j] = max(DP[j], DP[j - itemWeight[i]] + itemPrice[i]);
        }
    }

    totalPrice = DP[MaxWeight];

    cout << totalPrice << '\n';
    
    return 0;
}