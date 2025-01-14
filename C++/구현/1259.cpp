#include <iostream>

using namespace std;

int a, dev = 0;
int arr[5] = {0, 0, 0, 0, 0};
bool bFelindrop = true;

int main()
{
    while(1)
    {
        cin >>a;

        if(a == 0)
            break;

        int tempA = a;

        while(a >= 10)
        {
            a /= 10;
            dev++;
        }

        for(int i = dev; i >= 0; i--)
        {
            arr[i] = tempA % 10;
            tempA /= 10;
        }

        for(int i = 0; i < (dev + 1) / 2; i++)
        {
            if(arr[i] != arr[dev - i])
                bFelindrop = false;
        }

        if(bFelindrop == true)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        dev = 0;
        bFelindrop = true;
    }

    return 0;
}