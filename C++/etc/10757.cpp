#include <iostream>
#include<string.h>

using namespace std;

void reverse(char arr[])
{
    int len = strlen(arr);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    char A[10001] = { 0 };
    char B[10001] = { 0 };
    char res[10003] = { 0 };
    int len = 0, alpha = 0;

    cin >> A >> B;
    reverse(A);
    reverse(B);
    if (strlen(A) > strlen(B))
        len = strlen(A); 
    else
        len = strlen(B);
    for (int i = 0; i < len; i++)
    {
        int sum = (A[i] - '0') + (B[i] - '0') + alpha;
        if (sum < 0)//한쪽이 비었을 경우
            sum += '0';
        if (sum >= 10)
            alpha = 1;
        else
            alpha = 0;
        res[i] = sum % 10 + '0';
    }
    if (alpha == 1)
        res[len] = '1';
    reverse(res);
    cout << res << '\n';
    return 0;
}
