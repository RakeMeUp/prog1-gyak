#include <iostream>

class B1 {
public:
    virtual void vf() const { std::cout << "B1::vf\n"; };
    void f() const { std::cout << "B1::f\n"; };
};

class D1 : public B1 {
public:
    void vf() const override { std::cout << "D1::vf\n"; };
};

int main(){

    B1 b;
    b.vf();
    b.f();

    D1 d;
    d.vf();
    d.f();

    B1& ref = d;
    d.vf();
    d.f();


    return 0;
}