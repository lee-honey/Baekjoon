#include <iostream>

using namespace std;

int arr[8] = {0,};

bool ascending(int arr[])
{
    for(int i = 0; i < 8; i++)
    {
        if(arr[i] != i + 1)
            return false;
    }
    return true;
}

bool descending(int arr[])
{
    for(int i = 0; i < 8; i++)
    {
        if(arr[i] != 8 - i)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 8; i++)
        cin >> arr[i];

    if(true == ascending(arr))
        cout << "ascending" << '\n';
    else if(true == descending(arr))
        cout << "descending" << '\n';
    else
        cout << "mixed" << '\n';

    return 0;
}