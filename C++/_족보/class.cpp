#include <iostream>

using namespace std;

class CInfo
{
private:
	int m_iX;
	int m_iY;
public:
	void Output(void)
	{
		m_iX = 11;
		m_iY = 22;
		cout << m_iX << m_iY <<endl;
	}
};

int main(void)
{
    CInfo* pInfo;
    pInfo->Output();
    return 0;
}