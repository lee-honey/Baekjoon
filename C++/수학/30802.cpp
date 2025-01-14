#include <iostream>

using namespace std;

int N, T, P, hap = 0;
int arr[6] = {0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < 6; i++)
        cin >> arr[i];

    cin >> T >> P;

    for(int i = 0; i < 6; i++)
    {
        hap += arr[i] / T;
        if(arr[i] % T != 0)
            hap += 1;
    }
    
    cout << hap << endl;
    hap = 0;
    
    for(int i = 0; i < 6; i++)
        hap += arr[i];

    cout << hap / P << " " << hap % P << '\n';

    return 0;
}