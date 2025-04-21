#include <iostream>

using namespace std;

float ComputeAverage(빈칸, int nSize)
{
    float fAverage = 0;
    for (int i = 0; i < nSize; ++i)
    {
        fAverage += 빈칸칸;
    }
    return fAverage / nSize;
}

int main(void)
{
    int Array[10] = {1,2,3,4,5,6,7,8,9,10};
    cout <<"Average = " << ComputeAverage(Array, 빈칸);
    return 0;
}