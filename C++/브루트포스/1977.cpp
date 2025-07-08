#include <iostream>
#include <vector>

using namespace std;

int M(0), N(0);
vector<int> vec;
int hap(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for(int i = 1; i <= 10000; i++)
    {
        if(M <= i * i && i * i <= N)
        {
            vec.push_back(i * i);
            hap += i * i;
        }
    }

    if(vec.size() != 0)
    {
        cout << hap << '\n';
        cout << vec[0] << '\n';
    }
    else
        cout << "-1" << '\n';

    return 0;
}