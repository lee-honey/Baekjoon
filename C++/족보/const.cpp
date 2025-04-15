#include <iostream>

using namespace std;

class CObj
{
	private:
		int m_X, m_Y, m_Z;
	public:
		void SetXYZ(int x, int y, int z) const
		{
		    m_X = x; m_Y = y; m_Z = z;
		}
	public:
		int GetX() const { return x; }
		int GetY() const { return y; }
		int GetZ() const { return z; }
}