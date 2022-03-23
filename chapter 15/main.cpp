#include <iostream>
#include "std_lib_facilities.h"


class Person{
public:
    Person(std::string x, int y): name(x),age(y) {}
    std::string get_name() const {
        return name;
    };
    int get_age() const{
        return age;
/*     };
    void set_name(std::string str){
        name = str;
    };
    void set_age(int number){
        age = number;
    }; */
private:
    std::string name;
    int age;
};

ostream& operator<<(ostream& os, const Person& p){
    os << p.get_name() << " - " << p.get_age();
    return os;
};

istream& operator>>(istream& is, Person& p){
/*  std::string str;
    is >> str;
    p.set_name(str);
    int age;
    is >> age;
    p.set_age(age);
    return is; */

    std::string name;
    int age;
    
};



int main(){

    Person p{"Goofy", 63};

    std::cout << p << std::endl;

    return 0;
}