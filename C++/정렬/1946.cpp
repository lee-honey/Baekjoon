#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T(0), N(0), a(0), b(0), result(1);
bool failed = false;
int main(void)
{
    cin >> T;
    while(T--)
    {
        cin >> N;
        vector<pair<int, int>> arr;
        for (int i = 0; i < N; i++)
        {
            cin >> a >> b;
            arr.push_back({a, b});
        }
        sort(arr.begin(), arr.end()); //정렬부터 하고
        int temp = 0;
        for(int i = 1; i < N; i++)
        {
            if(arr[i].second > arr[temp].second) //그다음 뒤에값만 대소비교 하면 바로 구하기 가능
                failed = true;

            if(failed == false) // 지금 우리가 비교하려는 값이 떨어질 조건의 사람이 아니면
            {                                                                                                                                                          
                result++;
                temp = i; // first는 정렬을 했으니까 발린게 당연한데, second가 이길 조건이 된다면 그것에 대해 이겨야함
            }
            else
                failed = false;
        }
        cout << result << endl;
        result = 1;
    }
    return 0;
} 