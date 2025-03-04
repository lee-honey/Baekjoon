// 별찍기 - 모든 위치 x,y에 대해 재귀문을 수행하는것이 일반적 방법

#include <iostream>

using namespace std;

int N(0);

void Jaegui(int i, int j, int n)
{
    if((i / n) % 3 == 1 && (j / n) % 3 == 1) // n으로 나눈 값을 3으로 나눴을때의 나머지가 i, j각각 1인 경우
        cout << " "; // 빈칸출력력
    else if(n < 3) // 위 조건에 해당되지 않으면서 끝까지 내려왔으면 "*" 출력
        cout << "*";
    else
        Jaegui(i, j, n / 3);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Jaegui(i, j, N); // 모든 위치에 대해 재귀문을 수행함
        }
        cout << "\n";
    }

    return 0;
}