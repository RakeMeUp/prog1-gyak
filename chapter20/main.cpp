#include <vector>
#include <list>
#include <array>
#include <iostream>
#include <algorithm>

template<typename T>
void increase(T& cont, int amount){
    for(auto& item : cont){
        item = item + amount;
    }
};
template<typename T>
void print_it(T& cont){
    for(auto& item : cont){
        std::cout<<item;
    }
    std::cout<< std::endl;
}

template<typename Iter1, typename Iter2>
Iter2 new_copy(Iter1 or_begin, Iter1 or_end, Iter2 target_begin){
    for(Iter1 i = or_begin; i != or_end; ++i){
        *target_begin = *i;
        target_begin++;
    }
    return target_begin;
}

int main(){
    std::array<int, 10> arr = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> vec {0,1,2,3,4,5,6,7,8,9};
    std::list<int> intList {0,1,2,3,4,5,6,7,8,9};

    /* int arr2[10];
    for(int i = 0; i < 10; ++i){
        arr2[i] = arr[i];
    }; */
    std::array<int, 10> arr2 = arr;
    std::vector<int> vec2 = vec;
    std::list<int> intList2 = intList;

    increase(arr2, 2);
    increase(vec2, 3);
    increase(intList2, 5);

    new_copy(arr.begin(),arr.end(),vec2.begin());
    new_copy(intList.begin(),intList.end(),arr2.begin());

    print_it(arr);
    print_it(arr2);
    print_it(vec);
    print_it(vec2);
    print_it(intList);
    print_it(intList2);

    std::vector<int>::iterator find_3;

    find_3 = std::find(vec.begin(), vec.end(), 3);
    if(find_3 != vec.end()){
        std::cout << "Found at " << *find_3 <<std::endl;
    }else{
        std::cout << "this aint it chief" << std::endl;
    }

    std::list<int>::iterator find_27;

    find_27 = std::find(intList.begin(), intList.end(), 27);
    if(find_27 != intList.end()){
        std::cout << "Found at " << *find_27 <<std::endl;
    }else{
        std::cout << "this aint it chief" << std::endl;
    }


    return 0;
}