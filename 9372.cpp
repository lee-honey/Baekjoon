#include <iostream>
using namespace std;

int main()
{
    int T, N, M;
    int a, b;
    int i;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        for (i = 0; i < M; i++)
        {
            cin >> a >> b;
        }
        cout << N - 1 << endl;
    }
}

//https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html