#include <iostream>

using namespace std;

int N(0), A(0), B(0), result(0);
int Arr[101][101] = {{0,0},};

int main(void)
{
    cin >> N;
    while(N--)
    {
        cin >> A >> B;
        for(int y = B; y < B + 10; y++)
        {
            for(int x = A; x < A + 10; x++)
            {
                Arr[y][x] = 1;
            }
        }
    }

    for(int y = 0; y < 101; y++)
    {
        for(int x = 0; x < 101; x++)
        {
            if(Arr[y][x] == 1)
                result++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}