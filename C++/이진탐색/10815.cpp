#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int N(0), M(0), lt(0), rt(0), mid(0);

int main(void)
{
    cin >> N;

    int sangLst[N] = {0,};

    for (int i =0; i < N; i++)
    {
        cin >> sangLst[i];
    }

    sort(sangLst, sangLst + N); // sort(배열의 포인터, 배열의 포인터 + 배열의 크기);
    
    cin >> M;

    int compLst[M] = {0,};
    int ansLst[M] = {0,};

    for (int i =0; i < M; i++)
    {
        cin >> compLst[i];
    }

    for (int i = 0; i < M; i++)
    {
        lt = 0;
        rt = N - 1;
        while (lt <= rt)
        {
            mid = (lt + rt) / 2;
            if (compLst[i] == sangLst[mid]) //target과 리스트값 비교
            {
                ansLst[i] = 1;
                break;
            }
            else if (compLst[i] < sangLst[mid])
                rt = mid - 1;
            else 
                lt = mid + 1;
        }
    }

    for(int i = 0; i < M; i++)
    {
        cout << ansLst[i] << " ";
    }

    return 0;
}