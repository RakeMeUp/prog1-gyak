#include <iostream>
#include <string>

class B1 {
public:
    virtual void vf() const { std::cout << "B1::vf\n"; };
    virtual void pvf() = 0;
    void f() const { std::cout << "B1::f\n"; };
};

class D1 : public B1 {
public:
    void vf() const override { std::cout << "D1::vf\n"; };
    void f() const { std::cout << "D1::f\n"; };
};

class D2 : public D1{
    public:
    void pvf() override { std::cout << "D2::pvf\n"; }
};

class B2 {
    public:
    virtual void pvf() const = 0;
};

class D21 : public B2 {
    public:
    std::string strMember = "im here yo";
    void pvf() const override { std::cout << strMember << std::endl; };
};
class D22 : public B2 {
    public:
    int strMember = 9;
    void pvf() const override { std::cout << strMember << std::endl; };
};

void f(B2& x){
    x.pvf();
};


int main(){

    D2 dd;
    dd.f();
    dd.vf();
    dd.pvf();
    
    D21 idk;
    D22 idc;
    f(idk);
    f(idc);


    return 0;
}