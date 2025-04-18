#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int>vecInt;
    int* pArray = NULL;
    vecInt.push_back(0);
    pArray = &vecInt[0];
    vecInt.push_back(1);

    cout << *pArray << endl;

    return 0;
}