#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N(0);
vector<string> guitars;

bool Cmp(const string& g1, const string& g2)
{
    if(g1.size() != g2.size())
        return g1.size() < g2.size();
    else
    {
        int temp1(0), temp2(0);
        for(int i = 0; i < g1.size(); i++)
        {
            if('0' <= g1[i] && g1[i] <= '9')
                temp1 += g1[i] - '0';
        }
        for(int i = 0; i < g2.size(); i++)
        {
            if('0' <= g2[i] && g2[i] <= '9')
                temp2 += g2[i] - '0';
        }
        if(temp1 != temp2)
            return temp1 < temp2;
    }
    return g1 < g2;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    guitars.resize(N);
    
    for(int i = 0; i < N; i++)
    {
        cin >> guitars[i];
    }

    sort(guitars.begin(), guitars.end(), Cmp);

    for(int i = 0; i < N; i++)
        cout << guitars[i] << '\n';

    return 0;
}