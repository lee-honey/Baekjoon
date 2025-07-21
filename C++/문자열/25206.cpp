#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string name[20];
double hakzeom[20];
unordered_map<string, double> grade;
double totalScore(0.0);
double totalNum(0.0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    grade["A+"] = 4.5;      grade["A0"] = 4.0;      grade["B+"] = 3.5;
    grade["B0"] = 3.0;      grade["C+"] = 2.5;      grade["C0"] = 2.0;
    grade["D+"] = 1.5;      grade["D0"] = 1.0;      grade["F"] = 0.0;

    for(int i = 0; i < 20; i++)
    {
        string gradeName;
        cin >> name[i] >> hakzeom[i] >> gradeName;
        if(gradeName != "P")
        {
            totalScore += hakzeom[i] * grade[gradeName];
            totalNum += hakzeom[i];
        }
    }

    cout.precision(7);
    if(totalScore == 0)
        cout << "0.000000" << '\n';
    else
        cout << totalScore / totalNum << '\n';

    return 0;
}