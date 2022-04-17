#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

template<typename T>
void print(T iter1, T iter2){
    while(iter1!=iter2){
        std::cout << *iter1;
        ++iter1;
    }
}
template<typename T, typename U>
void cin_to_map(std::map<T,U>& m){
    T key;
    U value;
    for(int i = 0; i < 3; i++){
        std::cin >> key >> value;
        m[key] = value;
    }
}

template<typename T, typename U, typename Op>
U accumulate(T first, T last, U init, Op oper){
    while(first!=last){
        init = oper(init, *first);
        ++first;
    }
    return init;
}

template<typename U, typename T>
struct map_sum{
    T operator()(T init, const std::pair<U,T>& rval){
        return init + rval.second;
    }
};

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T,U>& pair){
    os << pair.first << '\t' << pair.second << std::endl;
    return os;
}

template<typename T, typename U>
void copy_flipped_values(T begin, T last, U& target){
    while(begin != last){
        target[begin->second] = begin->first;
        ++begin;
    }
}  

int main(){

    std::map<std::string,int> msi;

    msi["lecture"] = 21;
    msi["university"] = 35;
    msi["education"] = 15;
    msi["school"] = 99;
    msi["kindergarten"] = 105;
    msi["river"] = 5;
    msi["city"] = 10;
    msi["capital"] = 70;
    msi["software"] = 88;
    msi["hardware"] = 43;

    print(msi.begin(), msi.end());
    
    msi.erase(msi.begin(), msi.end());

    cin_to_map(msi);
    print(msi.begin(), msi.end());

    int sum = accumulate(msi.begin(), msi.end(), 0, map_sum<std::string, int>());
    std::cout<< sum<< std::endl;

    std::map<int, std::string> mis;
    copy_flipped_values(msi.begin(), msi.end(), mis);

    print(mis.begin(), mis.end());
    return 0;
}