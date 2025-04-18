#include <iostream>

using namespace std;

class CObj
{
protected:
	static int m_iX;
};

int CObj::m_iX = 0;

class CPlayer: public CObj
{
public:
	void Init(void)
	{
	    m_iX = 11;
	}
};

class CMonster:public CObj
{
public:
	void Output(void)
	{
		cout << m_iX << endl;
	}
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    CObj* pPlayer = new CPlayer;
    CObj* pMonster= new CMonster;
    ((CPlayer*)pPlayer)->Init();
    ((CMonster*)pMonster)->Output();

    return 0;
}