#include <iostream>

using namespace std;

class Base
{
	public:
	 void a(){ cout << "Base ::a\n"; }
	 virtual void b(){ cout << "Base ::b\n"; }
};

class Derived : public Base
{
	public:
		void a(){ cout << "Derived::a\n"; }
		virtual void b(){ cout << "Derived::b\n"; }
};

int main(void)
{
	Derived d;
	Base* b = static_cast<Base*>(&d);
	
	d.a();
	b->a();
	d.b();
	b->b();

    return 0;
}