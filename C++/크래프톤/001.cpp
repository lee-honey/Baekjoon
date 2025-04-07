#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<double, double> P1, P2;
double S1, S2;
double theta;

void Transform(pair<double, double> temp, vector<double>& answer)
{
    double x = temp.first;
    double y = temp.second;

    x -= P1.first;    
    y -= P1.second;     // 원점으로 이동
    
    x *= S2 / S1;
    y *= S2 / S1;       // 크기 적용

    double newX = cos(theta) * x - sin(theta) * y;
    double newY = sin(theta) * x + cos(theta) * y;  // 회전(자전) 적용

    newX += P2.first;
    newY += P2.second;  // 이동

    answer.push_back(newX);
    answer.push_back(newY);
}

void solution(double A1, double A2, double B1, double B2, 
              double C1, double C2, double D1, double D2,
              double R1x, double R1y, double R2x, double R2y,
              double R3x, double R3y, double R4x, double R4y) 
{
    vector<double> answer;

    P1 = { (R1x + R2x) / 2, (R1y + R2y) / 2 };
    P2 = { (R3x + R4x) / 2, (R3y + R4y) / 2 };

    double angle1 = atan2(R2y - R1y, R2x - R1x);
    double angle2 = atan2(R4y - R3y, R4x - R3x);
    theta = angle2 - angle1;

    S1 = sqrt(pow((R2x - R1x) , 2) + pow((R2y - R1y) , 2));
    S2 = sqrt(pow((R4x - R3x) , 2) + pow((R4y - R3y) , 2));

    Transform({A1, A2}, answer);    Transform({B1, B2}, answer);
    Transform({C1, C2}, answer);    Transform({D1, D2}, answer);

    cout << answer[0] << " " << answer[1] << ' ';
    cout << answer[2] << " " << answer[3] << ' ';
    cout << answer[4] << " " << answer[5] << ' ';
    cout << answer[6] << " " << answer[7] << ' ';
}

int main() {
    solution(10, 10, -10, 10, -10, -10, 10, -10, -2, 0, 2, 0, -2, 0, 2, 3);
    return 0;
}
