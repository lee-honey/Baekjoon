#include <deque>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

int N(0), A(0), X(0);
deque<int> deq;

void Input(){
    cin >> N;
    while(N--)
    {
        cin >> A;
        switch(A)
        {
            case 1:
                cin >> X;
                deq.push_front(X);
                break;
            case 2:
                cin >> X;
                deq.push_back(X);
                break;
            case 3:
                if(!deq.empty())
                {
                    cout << deq.front() << '\n';
                    deq.pop_front();
                }
                else cout << "-1\n";
                break;
            case 4:
                if(!deq.empty())
                {
                    cout << deq.back() << '\n';
                    deq.pop_back();
                }
                else cout << "-1\n";
                break;
            case 5:
                cout << deq.size() << '\n';
                break;
            case 6:
                if(deq.empty()) cout << 1 << '\n';
                else cout << "0\n";
                break;
            case 7:
                if(!deq.empty())cout << deq.front() << '\n';
                else cout << "-1\n" ;
                break;
            case 8:
                if(!deq.empty())cout << deq.back() << '\n';
                else cout << "-1\n";
                break;
        }
    }
}

int main(void)
{
    FASTIO
    Input();
    return 0;
}