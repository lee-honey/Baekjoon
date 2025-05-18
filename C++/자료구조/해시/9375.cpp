#include <iostream>
#include <string>
#include <map>

using namespace std;

int iTestCase = 0;
map<string, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> iTestCase;

    while(iTestCase--)
    {
        int n = 0;
        cin >> n;
        while(n--)
        {
            int num = 0;
            string strName = "", strType = "";
            cin >> strName >> strType;
            mp[strType]++;
        }

        int hap = 1;

        for(auto m : mp)
            hap *= (m.second + 1);
        hap -= 1;
        cout << hap << '\n';
        mp.clear();
    }

    return 0;
}