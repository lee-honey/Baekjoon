// 분할정복 알고리즘
#include <iostream>
#include <cmath>

using namespace std;

int N(0), r(0), c(0), result(0);

void Jaegui(int x, int y, int size)
{
    if(c == x && r == y)
    {
        cout << result << '\n';
        return;
    }
    else if(x <= c && c < x + size && y <= r && r < y + size)
    {
        Jaegui(x, y, size / 2);
        Jaegui(x + size / 2, y, size / 2);
        Jaegui(x, y + size / 2, size / 2);
        Jaegui(x + size / 2, y + size / 2, size / 2);
    }
    else    // 더 높은값으로 가는 애는 이 구문에 들어오기 전에 지속되는 재귀에 의해 return조건에 들어가 더해지지 않는다.
    {
        result += size * size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    Jaegui(0, 0, pow(2, N));

    return 0;
}