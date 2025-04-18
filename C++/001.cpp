class Base{
private:
    int x;
public:
    void mf1();
    void mf1(int x);
};

class Derived: public Base{
    public:
    void mf1();
   
};

#include <iostream>

int main(void)
{
    Derived d;
    int x;

    d.mf1(x);
    return 0;
}

