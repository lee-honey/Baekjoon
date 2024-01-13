#include <iostream>
#include <algorithm>

using namespace std;

int n(0), m(0), tmp(0);
bool isExist(false);

int main()
{
    scanf("%d", &n);
    int arr[n] = {0,};
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);

    cin >> m;
    for(int i =0; i < m; i++){
        scanf("%d", &tmp);
        int start = 0;
        int last = n - 1;
        int midIdx;
        isExist = false;
        while(start <= last){
            midIdx = (start + last) / 2;
            if(tmp == arr[midIdx])
            {
                printf("1\n");
                isExist = true;
                break;
            }
            else if(tmp < arr[midIdx]) last = midIdx - 1;
            else start = midIdx + 1;
        }
        if(isExist == false)
            printf("0\n");
    }
    return 0;
}

int binarySearch(int len, int m, int arr[]){
    int start = 0;
    int last = len - 1;
    int midIdx;

    while(start <= last){
        midIdx = (start + last) / 2;
        if(m == arr[midIdx]) return 1;
        else if(m < arr[midIdx]) last = midIdx - 1;
        else start = midIdx + 1;
    }
    return 0;
}

//기본적으로 cin은 cout 에 바인딩되어 있어서 cin에서 i/o작업을 수행하기 전에 flush가 호출되어 IO 부담이 증가 합니다