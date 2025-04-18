#include <iostream>

using namespace std;

class A
{
	public:
		virtual void f() { cout << 1; }
		void g() { f(); }
};

class B : public A
{
	public:
		virtual void f() { cout << 2; }
		void g() { A::f(); }
};

int main(void)
{
	A a;
	B b;
	A* c = &b;
    
	a.f();
	a.g();
	b.f();
	b.g();
	c->f();
	c->g();
    return 0;
}