#include <vector>
#include <string>
#include <iostream>

template<typename T> struct S {
private:
    T val;
public:
    S(): val(T()) {}
    S(T v) : val(v){}

    T& get();
    T& get() const;
    void set(T newVal);
    void read_val(T& v);
    void operator=(const T& newVal);

};

template<typename T> T& S<T>::get() {
    return val;
};
template<typename T> T& S<T>::get() const {
    return val;
};
template<typename T> void S<T>::set(T newVal) {
    val = newVal;
};
template<typename T> void S<T>::operator=(const T& newVal){
    val = newVal;
    return val;
};
template<typename T> void read_val(T& v) {
        std::cin >> v;
};

int main(){

    S<int> idk_int(7);
    S<char> idk_char('D');
    S<double> idk_double(7.2);
    S<std::string> idk_string("ieffdup");
    std::vector<int> vec {1,2,3};
    S<std::vector<int>> idk_vector(vec);

    std::cout<<idk_int.get()<<std::endl;
    std::cout<<idk_char.get()<<std::endl;
    std::cout<<idk_double.get()<<std::endl;
    for(auto& item : idk_vector.get()){
        std::cout<<item<<std::endl;
    };

    read_val(idk_int.get());
    read_val(idk_char.get());
    read_val(idk_double.get());

    std::cout<<idk_int.get()<<std::endl;
    std::cout<<idk_char.get()<<std::endl;
    std::cout<<idk_double.get()<<std::endl;

    return 0;
}