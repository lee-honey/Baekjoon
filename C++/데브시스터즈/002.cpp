#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> field, int farmSize) {
    int answer = 2147483647;

    int M = field.size();
    int N = field[0].size();

    for(int i = 0; i <= M - farmSize; i++)
    {
        for(int j = 0; j <= N - farmSize; j++)
        {
            bool bHasPoison = false;
            int iStoneCnt = 0;
            for(int k = 0; k < farmSize; k++)
            {
                for(int l = 0; l < farmSize; l++)
                {
                    int now = field[i + k][j + l];
                    if(now == 2)
                    {
                        bHasPoison = true;
                        break;
                    }
                    if(now == 1)
                    {
                        iStoneCnt++;
                    }
                }
                if(bHasPoison == true)
                    break;
            }
            if(bHasPoison == false)
                answer = min(answer, iStoneCnt);
        }
    }

    if(answer == 2147483647)
        answer = -1;

    return answer;
}

int main(void)
{
    vector<vector<int>> field = 
        {{1, 0, 0, 0, 2},
         {0, 1, 0, 1, 0},
         {0, 0, 0, 1, 0}};
    int farmSize = 3;
    cout << solution(field, farmSize) << '\n';
    return 0;
}