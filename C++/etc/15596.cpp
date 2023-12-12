#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

long long sum(std::vector<int>& a)
{
    long long sum = 0;
    for (int i = 0; i < a.size(); i++)
        sum += a[i];
    return sum;
}

int main()
{
    vector<int> a = { 1, 2, 3, 4, 5 };
    printf("%d\n", sum(a));
}