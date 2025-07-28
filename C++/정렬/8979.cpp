#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct country
{
    int num;
    int gold;
    int silver;
    int bronze;
};

bool Cmp(const country& c1, const country& c2)
{
    if(c1.gold > c2.gold)
        return true;
    if(c1.gold == c2.gold)
    {
        if(c1.silver > c2.silver)
            return true;
        if(c1.silver == c2.silver)
        {
            if(c1.bronze > c2.bronze)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

int N(0);
int K(0);
vector<country> vec(N);
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    vec.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i].num >> vec[i].gold >> vec[i].silver >> vec[i].bronze;
    }

    sort(vec.begin(), vec.end(), Cmp);

    int temp(0);
    for(int i = 0; i < N; i++)
    {
        if(i > 0 && vec[i].gold == vec[i - 1].gold && vec[i].silver == vec[i - 1].silver && vec[i].bronze == vec[i - 1].bronze)
        {   temp++; }
        else
        {
            if(temp != 0)
            {
                ans += temp;
                temp = 0;
            }
            ans++;
        }

        if(vec[i].num == K)
            break;
    }

    cout << ans << '\n';

    return 0;
}