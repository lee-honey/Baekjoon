#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N(0), M(0);
vector<vector<int>> vecParty;
queue<int> queKnown;

bool CanLie(vector<int> v, int i)
{
    auto it = find(v.begin(), v.end(), i);
    if(it != v.end())   return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int iKnownNum;
    cin >> iKnownNum;
    for(int i = 0; i < iKnownNum; i++)  // 아는사람들을 queue에 배치
    {
        int iKnown;
        cin >> iKnown;
        queKnown.push(iKnown);
    }

    for(int i = 0; i < M; i++)      // 파티 간 사람들 vector<vector<int>>에 초기화
    {
        int iPartyNum;
        cin >> iPartyNum;
        vector<int> vecTemp;
        for(int j = 0; j < iPartyNum; j++)
        {
            int iParty;
            cin >> iParty;
            vecTemp.push_back(iParty);
        }
        vecParty.push_back(vecTemp);
    }

    while(!queKnown.empty())
    {
        int iKnown = queKnown.front();
        queKnown.pop();

        for(int i = 0; i < vecParty.size(); i++)
        {
            if(CanLie(vecParty[i], iKnown))
            {
                for(auto it : vecParty[i])
                {
                    if(it != iKnown)
                        queKnown.push(it);
                }
                vecParty.erase(vecParty.begin() + i);
                i--;
            }
        }
    }

    cout << vecParty.size() << '\n';

    return 0;
}