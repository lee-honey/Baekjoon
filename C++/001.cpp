#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int*> vec(10);
    int* p = new int(10);
    vec[3] = p;
    vec.reserve(200);
    cout << *(vec[3]) << '\n';

    return 0;
}