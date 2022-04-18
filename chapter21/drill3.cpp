#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>

template<typename T>
void print(T first, T last) {
    while(first!=last){
        std::cout << *first << std::endl;
        ++first;
    }
}

template<typename T, typename U>
void print_pair(T first, T last, U first2) {
    while(first!=last){
        std::cout << *first << "\t" << *first2 << std::endl;
        ++first;
        ++first2;
    }
}

struct less_than{
    double x;
    less_than(double xx): x(xx) {}
    bool operator()(const double value){
        return value < x;
    }
};

int main(){
    std::vector<double> vd;
    std::vector<double> vd2(16);
    std::vector<int> vi(16);

    std::fstream file {"db_source.txt"};
    if(!file){
        throw std::runtime_error("error at file reading");
    }

    double item;
    while(file >> item){
        vd.push_back(item);
    }

    print(vd.begin(), vd.end());
    
    std::copy(vd.begin(), vd.end(), vi.begin());

    print(vi.begin(), vi.end());

    print_pair(vd.begin(), vd.end(), vi.begin());

    double sum_d = std::accumulate(vd.begin(), vd.end(), 0.0);
    int sum_i = std::accumulate(vi.begin(), vi.end(), 0);
    double vd_mean = sum_d / vd.size();

    std::cout << sum_d 
    <<'\t'<< sum_i
    <<"\tdiff: "<< sum_d - sum_i 
    << "\tmean: " << vd_mean
    << std::endl;

    reverse(vd.begin(), vd.end());

    print(vd.begin(), vd.end());

    //this is dumb
    auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(), [vd_mean](double i){return (i<vd_mean);});
    vd2.resize(std::distance(vd2.begin(), it));

    print(vd2.begin(),vd2.end());

    std::sort(vd.begin(), vd.end());
    print(vd.begin(),vd.end());


    return 0;
}