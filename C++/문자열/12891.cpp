#include <iostream>
#include <deque>
#include <string>
#include <unordered_map>

using namespace std;

int S(0), P(0);
string DNA;
int ACGT[4] = {0,};
unordered_map<char, int> mp;
deque<int> deqDNA;
int ans(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S >> P;
    cin >> DNA;
    for(int i = 0; i < 4; i++)
    {
        cin >> ACGT[i];
    }

    for(int i = 0; i < P; i++)
    {
        deqDNA.push_back(DNA[i]);
        mp[DNA[i]]++;
    }

    if(ACGT[0] <= mp['A'] && ACGT[1] <= mp['C'] &&
        ACGT[2] <= mp['G'] && ACGT[3] <= mp['T'])
        ans++;

    for(int i = 1; i <= S - P; i++)
    {
        mp[DNA[i - 1]]--;
        deqDNA.pop_front();

        mp[DNA[P + i - 1]]++;
        deqDNA.push_back(DNA[P + i - 1]);

        if(ACGT[0] <= mp['A'] && ACGT[1] <= mp['C'] &&
            ACGT[2] <= mp['G'] && ACGT[3] <= mp['T'])
            ans++;
    }

    cout << ans << '\n';

    return 0;
}