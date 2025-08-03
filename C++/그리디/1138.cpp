#include <iostream>
#include <vector>

using namespace std;

int N(0);
vector<int> vec;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vec.resize(N);
    for(int i = 1; i <= N; i++)
    {
        int temp(0);
        cin >> temp;
        for(int j = 0; j < N;j++)
        {
            if(temp == 0 && vec[j] == 0) // 주어진 수만큼 ㄸㅟㄴ 자리에 0이며ㄴ 
            {
                vec[j] = i; // 가ㅄ 대입
                break;
            }
            if(vec[j] == 0) // 0이 나타나면 뛰어넘어
                temp--;
        }
    }

    for(int i = 0; i < N; i++)
        cout << vec[i] << " ";

    return 0;
}