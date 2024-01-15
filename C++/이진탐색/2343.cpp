#include <iostream>
#include <algorithm>
using namespace std;
// 이진탐색은 mid를 어떤 값으로 갖을지가 중요하다.
// 이 문제에서 우리가 구해야 할 값 mid : 블루레이 크기 중 최소 크기
int main(void)
{
    int N(0), M(0), lt(0), rt(0), mid(0), cnt(0), sum(0);
    int arr[100001] = {0,};
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i]; 
        rt += arr[i]; //가질 수 있는 가장 큰 블루레이 크기: 전체를 더한 값
    }
    lt = *max_element(arr, arr + N); //가질 수 있는 가장 작은 블루레이 크기 : ARR배열의 가장 큰 값

    while(lt <= rt)
    {
        mid = (lt + rt) / 2;
        sum = 0;
        cnt = 0;
        for(int i = 0; i < N; i++) //배열을 전부 더할 때
        {
            if(sum + arr[i] > mid) //우리가 정한 mid보다 지금까지 더한 값이 커지면
            {
                sum = 0; //합의 값을 초기화시키고
                cnt++; // m값과 비교하기 위해 cnt를 증가시킨다.
            }
            sum += arr[i]; //위의 if문에 해당하지 않을 경우 for문이 한번 돌 때마다 sum에 값을 추가시키고
        }
        if(sum != 0) cnt++; //for문을 다 돌았을 경우에 남은 값이 있는 경우 그것까지 cnt를 증가시켜준다.

        if(cnt > M)
            lt = mid + 1; //이렇게 나온 cnt가 M보다 클 경우 lt범위를 키워주고
        else
            rt = mid - 1; //그렇지 않을 경우 rt범위를 줄여준다.
    }
    cout << lt << endl;
    return 0;
}