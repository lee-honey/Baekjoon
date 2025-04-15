#include <iostream>
#include <cstring>
using namespace std;

class CName
{
private:
    int   m_iSize;
    char* m_pName;

public:
    CName(const char* pName)
    {
        m_iSize = strlen(pName);
        m_pName = new char[m_iSize + 1];
        strcpy(m_pName, pName);
    }
	 
    ~CName()
    {
        cout << "I'm free" << '\n';
        delete[] m_pName;
    }
		
    void PrintName()
    {
        cout << m_pName << '\n';
    }
};

void PrintN(CName name)
{
    name.PrintName();
}

int main(void)
{
    CName name("neo-people"); 
    PrintN(name);

    return 0;
};