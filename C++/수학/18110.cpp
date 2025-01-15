#include <iostream>
#include <algorithm>

using namespace std;
int arr[300000] = {0,};
int hap = 0;
float num = 0;
float fAverage = 0;

int n = 0, i = 0;

int MyRound(float num)
{
    float temp = num * 10.f;
    if((int)(temp) % 10 >= 5)
        return (int)num + 1;
    else
        return (int)num;
}

int main()
{
    cin >> n;
    if(n == 0)
        cout << 0 << endl;
    else
    {
        num = n * 15.f / 100.f;
        num = MyRound(num);

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        for(int i = num; i < n - num; i++)
        {
            hap += arr[i];
        }
        
        fAverage = hap / (float)(n - 2 * num);
        fAverage = MyRound(fAverage);

        cout << (int)fAverage << endl;
    }

    return 0;
}