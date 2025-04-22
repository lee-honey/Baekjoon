#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

constexpr double BallDiameter = 2;

int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector) {
    int answer = -2;
    double minT = 1e9;

    // 방향벡터 정규화
    double hitVecLen = sqrt(hitVector[0] * hitVector[0] + hitVector[1] * hitVector[1]);
    double hitX = hitVector[0] / hitVecLen;
    double hitY = hitVector[1] / hitVecLen;
    
    for(int i = 0; i < objectBallPosList.size(); i++)
    {
        double dX = objectBallPosList[i][0];
        double dY = objectBallPosList[i][1];

        double A = hitX * hitX + hitY * hitY;
        double B = -2 * (dX * hitX + dY * hitY);
        double C = dX * dX + dY * dY - BallDiameter * BallDiameter;

        // (hitX * t, hitY * t)와 (dX, dY) 사이의 거리가 BallDiameter * 2 미만일 것.
        // 이를 식으로 풀면 t 기준의 이차방정식이 나옴. t에 해당하는 두 실근이 둘 다 양수여야할 것.
        // 이차함수를 그렸을 때, f(t)가 0 미만이 되는 동안 두 원은 접한다고 봄.

        double D = B * B - 4 * A * C; // 판별식
        if(D <= 0)
            continue;

        double t = 1e9;
        double sqrtD = sqrt(D);
        double t1 = (-B - sqrtD) / (2 * A);
        double t2 = (-B + sqrtD) / (2 * A);

        if(t1 > 0)
            t = t1;
        else if(t2 > 0)
            t = t2;

        if(t < minT)
        {
            answer = i;
            minT = t;
        }
    }

    return answer;
}

int main(void)
{
    vector<vector<double>> objectBallPosList = {{5,5},{3,3},{2,1}};
    vector<double> hitVector = {1,1};
    cout << solution(objectBallPosList, hitVector) << '\n' ;
    return 0;
}