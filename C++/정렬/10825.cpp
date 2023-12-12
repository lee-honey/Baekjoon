#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
    string name;
    int korScore;
    int matScore;
    int engScore;
};

bool cmp(Student a, Student b) {
    if (a.korScore == b.korScore && a.engScore == b.engScore && a.matScore == b.matScore) return a.name < b.name;
    if (a.korScore == b.korScore && a.engScore == b.engScore) return a.matScore > b.matScore;
    if (a.korScore == b.korScore) return a.engScore < b.engScore;
    return a.korScore > b.korScore;
}

int main()
{
    int N;
    cin >> N;
    Student student[N];
    for (int i = 0; i < N; i++)
    {
        cin >> student[i].name >> student[i].korScore 
        >> student[i].engScore >> student[i].matScore;
    }
    sort(student, student + N, cmp);
    for(int i = 0; i < N; i++)
    {
        cout << student[i].name << '\n';
    }
}
