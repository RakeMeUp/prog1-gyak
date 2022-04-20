#include <iostream>
#include <cmath>
#include <complex>
#include "Matrix.h"
#include "MatrixIO.h"

void print_sizes(){
    std::cout<< "char " << sizeof(char) << std::endl;
    std::cout<< "short " << sizeof(short) << std::endl;
    std::cout<< "int " << sizeof(int) << std::endl;
    std::cout<< "long " << sizeof(long) << std::endl;
    std::cout<< "float " << sizeof(float) << std::endl;
    std::cout<< "double " << sizeof(double) << std::endl;
    std::cout<< "int* " << sizeof(int*) << std::endl;
    std::cout<< "double* " << sizeof(double*) << std::endl;
}

void print_matrix(){
    Numeric_lib::Matrix<int> a(10);
    Numeric_lib::Matrix<int> b(100);
    Numeric_lib::Matrix<double> c(10);
    Numeric_lib::Matrix<int,2> d(10,10);
    Numeric_lib::Matrix<int,3> e(10,10,10);
    std::cout   << "matrix int " << sizeof(a) << std::endl
                << "matrix 100 " << sizeof(b) << std::endl
                << "matrix db " << sizeof(c) << std::endl
                << "matrix in,2 " << sizeof(d) << std::endl
                << "matrix in,3 " << sizeof(e) << std::endl;

    std::cout   << "num of elements" << std::endl
                << "elements of matrix int " << a.size() << std::endl
                << "elements of matrix 100 " << b.size() << std::endl
                << "elements of matrix db " << c.size() << std::endl
                << "elements of matrix in,2 " << d.size() << std::endl
                << "elements of matrix in,3 " << e.size() << std::endl;
}

void sqrt_from_cin(){

    while(std::cin){
        int num;
        std::cin >> num;
        if(num <= 0) {
            std::cout<< "no sqrt value" <<std::endl;
        }else{
            std::cout << "sqrt of " << num << "is: " << std::sqrt(num) << std::endl;
        }
    }
}

void read_to_matrix(){
    
    Numeric_lib::Matrix<double> dbm(10);

    for(int i = 0; i < 10; ++i){
        std::cin >> dbm[i];
    }
    std::cout << dbm;
}

void make_multi_table(){
    int n, m;
    std::cout << "Rows?" << std::endl;
    std::cin >> n;
    std::cout << "Columns?" << std::endl;
    std::cin >> m;
    Numeric_lib::Matrix<int,2> multi(n,m);
    std::cout << multi << std::endl;
    for(int i = 0; i < multi.dim1(); ++i){
        for(int j = 0; j < multi.dim2(); ++j){
            multi(i,j) = (i+1)*(j+1);
        }
    }
    std::cout << multi << std::endl;
}

void complexes(){
    Numeric_lib::Matrix<std::complex<double>> dcm(10);
    for(int i = 0; i < 10; ++i){
        std::cin >> dcm[i];
    }
    std::cout << dcm << std::endl;
    std::complex<double> sum;
    for(int i = 0; i<dcm.dim1(); ++i){
        sum += dcm[i];
    }
    std::cout << sum << std::endl;
}

int main(){

    //print_sizes();

    //print_matrix();

    //sqrt_from_cin();

    //read_to_matrix();

    //make_multi_table();

    //complexes();
    
    Numeric_lib::Matrix<int,2> m(2,3);
    for(int i = 0; i<m.dim1(); ++i){
        for(int j = 0; j<m.dim2(); ++j){
            std::cin>> m(i,j);
        }
    }
    std::cout<<m<<std::endl;

    return 0;
}