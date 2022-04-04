#include <vector>
#include <iostream>
#include <stdexcept>

std::ostream& print_array10(std::ostream& os, int* a){
    for(int i = 0; i<10; ++i){
        os << a[i] << std::endl;
    }
    return os;
};

std::ostream& print_array(std::ostream& os, int* a, int n){
    for(int i = 0; i<n; ++i){
        os << a[i] << std::endl;
    }
    return os;
};

std::ostream& print_vector(std::ostream& os, std::vector<int> v){
    for(int i = 0; i<v.size(); ++i){
        os << v[i] << std::endl;
    }
    return os;
};

int main(){
    try{
        int* arr = new int[10];
        int* arr2 = new int[10] {100,101,102,103,104,105,106,107,108,109};
        int* arr3 = new int[11] {100,101,102,103,104,105,106,107,108,109, 110};
        int* arr4 = new int[20] {100,101,102,103,104,105,106,107,108,109, 110, 111,112,113,114,115,116,117,118,119};
        std::vector<int> vec1{100,101,102,103,104,105,106,107,108,109};
        std::vector<int> vec2{100,101,102,103,104,105,106,107,108,109,110};
        std::vector<int> vec3{100,101,102,103,104,105,106,107,108,109, 110, 111,112,113,114,115,116,117,118,119};

        /* for(int i = 0; i<10;++i){
            std::cout<<arr[i]<<std::endl;
        };

        delete[] arr; */
        print_array10(std::cout, arr);
        print_array10(std::cout, arr2);
        print_array10(std::cout, arr3);

        print_array(std::cout, arr4, 20);

        print_vector(std::cout, vec1);

        delete[] arr, arr2, arr3, arr4;
        return 0;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return -1;
    }
    catch(...){
        std::cerr<<"idk u fucked up" << std::endl;
        return -2;
    }

}