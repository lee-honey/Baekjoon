#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct person
{
    string name;
    int day;
    int month;
    int year;
};

int n(0);
vector<person> people;

bool Cmp(const person& p1, const person& p2)
{
    if(p1.year > p2.year)
        return true;
    else
    {
        if(p1.year == p2.year)
        {
            if(p1.month > p2.month)
                return true;
            else
                return (p1.month == p2.month) ? (p1.day > p2.day) : false;
        }
        else
            return false;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    people.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> people[i].name >> people[i].day >> people[i].month >> people[i].year;
    }

    sort(people.begin(), people.end(), Cmp);

    cout << people.front().name << '\n';
    cout << people.back().name << '\n';

    return 0;
}