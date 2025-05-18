#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> quest) {
    int answer = 0;

    sort(quest.begin(), quest.end());

    int iScore = 0;
    for(const auto& iter : quest)
    {
        if(iter[0] <= iScore)
        {
            answer++;
            iScore += iter[1];   
        }
    }

    return answer;
}

int main(void)
{
    vector<vector<int>> quest = {{12,5},{14,3},{3,4},{0,3},{7,3}};

    cout << solution(quest) << '\n';

    return 0;
}