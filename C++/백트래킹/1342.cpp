#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string S;
char arr[10];
bool bIsVisited[10] = {false, };
int ans(0);
unordered_map<char, int> alpha;
int mod(1);

void BackTracking(int depth)
{
    if(depth == S.size())
    {
        ++ans;
        return;
    }

    for(int i = 0; i < S.size(); i++)
    {
        if(bIsVisited[i] == false && (depth == 0 || (arr[depth - 1] != S[i])))
        {
            bIsVisited[i] = true;
            arr[depth] = S[i];
            BackTracking(depth + 1);
            bIsVisited[i] = false;
        }
    }
}

int Factorial(int N)
{
    if(N == 1)
        return 1;

    return N * Factorial(N - 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    for(int i = 0; i < S.size(); i++)
        alpha[S[i]]++;

    for(auto iter = alpha.begin(); iter != alpha.end(); iter++)
        mod *= Factorial(iter->second);
    
    BackTracking(0);

    cout << ans / mod << '\n';

    return 0;
}