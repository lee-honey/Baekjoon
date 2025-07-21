#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N(0), M(0);

struct frequent
{
    string word;
    int cnt;
};

vector<frequent> words;
unordered_map<string, int> mp;

bool Cmp(const frequent &word1, const frequent &word2)
{
    if(word1.cnt != word2.cnt)
        return word1.cnt > word2.cnt;
    if(word1.word.size() != word2.word.size())
        return (word1.word.size() > word2.word.size());
    return (word1.word < word2.word);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        if(temp.size() >= M)
            mp[temp]++;
    }

    words.resize(mp.size());
    int i(0);
    for(auto iter : mp)
        words[i++] = {iter.first, iter.second};

    sort(words.begin(), words.end(), Cmp);

    for(int i = 0; i < words.size(); i++)
        cout << words[i].word << '\n';

    return 0;
}