#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A, B;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    int minCnt(A.size());
    
    for(int i = 0; i <= B.size() - A.size(); i++)
    {
        int temp(0);
        for(int j = 0; j < A.size(); j++)
        {
            if(A[j] != B[i + j])
                ++temp;
        }
        minCnt = min(temp, minCnt);
    }

    cout << minCnt << '\n';

    return 0;
}