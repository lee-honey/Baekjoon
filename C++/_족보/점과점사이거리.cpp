#include <iostream>

using namespace std;

class Point
{
public:
    int x;
    int y;

Point(int x, int y)
{
    x = x, y = y;
}

float ComputeDistance(Point b)
{
    return sqrt((float)(x - b.x) * (x - b.x) + (float)(y - b.y) * (y - b.y)); }
};

int main(void)
{
    Point* pA = NULL;
    Point* pB = NULL;
    pA = new Point(0, 0);
    pB = new Point(1, 1);
    cout << "Distance=" << pA->ComputeDistance(*pB);

    return 0;
}