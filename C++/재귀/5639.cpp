#include <iostream>

using namespace std;

int tree[10000];

void PostOrder(int start, int end)
{
    if(start >= end)
        return;

    if(start == end - 1)
    {
        cout << tree[start] <<'\n';
        return;
    }

    int idx = start + 1;
    while(idx < end)
    {
        if(tree[start] < tree[idx])
            break;
        idx++;
    }

    PostOrder(start + 1, idx);
    PostOrder(idx, end);
    cout << tree[start] << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n(0);
    int idx(0);
    while(cin >> n)
    {
        tree[idx++] = n;
    }

    PostOrder(0, idx);

    return 0;
}