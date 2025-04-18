#include <iostream>

using namespace std;

class CObj
{
public:
    CObj()
    {
        cout << 1;
    }

    ~CObj()
    {
        cout << 2;
    }
};

class CPlayer:public CObj
{
public:
    CPlayer() : CObj()
    {
        cout << 3;
    }
    
    ~CPlayer()
    {
        cout << 4;
    }
};

int main(void)
{
    CObj* pPlayer = new CPlayer;
    
    delete pPlayer;
    
    return 0;
}