#include <iostream>
#include <string>

using namespace std;

string arr[3] = {"",};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 3; i++)
        cin >> arr[i];

    int num = 0;
    int hint = 0;

    for(int i = 0; i < 3; i++)
    {
        if(arr[i] != "Fizz" && arr[i] != "Buzz" && arr[i] != "FizzBuzz")
        {
            hint = atoi(arr[i].c_str());
            num = i;
        }
    }

    int result = hint + (2 - num) + 1;

    if(result % 3 == 0 && result % 5 == 0)
        cout << "FizzBuzz" << '\n';
    else if(result % 3 == 0)
        cout << "Fizz" << '\n';
    else if(result % 5 == 0)
        cout << "Buzz" << '\n';
    else
        cout << result << '\n';
    return 0;
}