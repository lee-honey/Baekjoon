#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N(0), M(0), lt(0), rt(0), mid(0), cnt(0), result(0);
    cin >> N >> M;
    int colors[M] = {0,};
    for (int i = 0; i < M; i++)
    {
        cin >> colors[i] ;
    }
    sort(colors, colors + M);
    lt = 1;
    rt = colors[M - 1];
    while(lt <= rt)
    {
        mid = (lt + rt) / 2;
        cnt = 0;
        for(int i = 0; i < M; i++)
        {
            if(colors[i] % mid ==0)
            {
                cnt += colors[i] / mid;
            }
            else
                cnt += colors[i] / mid + 1;
        }
        if(cnt <= N) //질투심의 최솟값을 구하는 것이므로 rt를 새로 할당하고 result는 그 rt의 한칸 오른쪽에 있는 값이어야 최솟값이 됨.
        {            //result가 어떤 범위에 포함되어야 하는지 잘 확인하기.
            rt = mid - 1;
            result = mid;
        }
        else
        {
            lt = mid + 1;
        }
    }
    cout << result << endl;
}