#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string strA, strB;
int A(0), B(0);
int minAns(0), maxAns(0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> strA >> strB;

    string minA(strA), minB(strB), maxA(strA), maxB(strB);

    for(int i = 0; i < strA.size(); i++)
    {
        if(strA[i] == '6')      minA[i] = '5';
        else if(strA[i] == '5') maxA[i] = '6';
    }
    for(int i = 0; i < strB.size(); i++)
    {
        if(strB[i] == '6')      minB[i] = '5';
        else if(strB[i] == '5') maxB[i] = '6';
    }

    int minNum = atoi(minA.c_str()) + atoi(minB.c_str());
    int maxNum = atoi(maxA.c_str()) + atoi(maxB.c_str());

    cout << minNum << " " << maxNum << '\n';
 
    return 0;
}