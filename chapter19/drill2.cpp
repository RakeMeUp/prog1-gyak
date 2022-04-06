#include <vector>
#include <iostream>

std::ostream& print_array(std::ostream& os, int* a, int n){
    for(int i = 0; i<n; ++i){
        os << a[i] << std::endl;
    }
    return os;
};

int main(){
    int x = 7;
    int* p1 = &x;

    int* p2 = new int[7] {1,2,4,8,16,32,64};

    std::cout << p1 << " " << *p1 << std::endl;
    std::cout << p2 << std::endl;
    for(int i = 0; i<7; ++i){
        std::cout << p2[i] << std::endl;
    }

    int* p3 = p2;
    p2 = p3;
    p2 = p1;

    std::cout << p1 << " " << *p1 << std::endl;
    std::cout << p2 << " " << *p2 << std::endl;

    delete[] p3;

    p1 = new int[10] {1,2,4,8,16,32,64,128,256,512};
    p2 = new int[10];

    for(int i = 0; i < 10; ++i ){
        p2[i] = p1[i];
    }

    std::cout << p2 << std::endl;
    for(int i = 0; i<10; ++i){
        std::cout << p2[i] << std::endl;
    }

    delete[] p1,p2;

    std::vector<int> vec1{1,2,4,8,16,32,64,128,256,512};
    std::vector<int> vec2(10);

    for(int i=0; i < vec1.size(); ++i){
        vec2[i]=vec1[i];
    }

    for(int i = 0; i<vec2.size(); ++i){
        std::cout << vec2[i] << std::endl;
    }

    return 0;
}