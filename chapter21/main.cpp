#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>

struct Item {
    std::string name;
    int iid;
    double value;

    Item(std::string x, int y, double z): name(x), iid(y), value(z) {};
    Item(): name(""), iid(0), value(0) {};
        
};

struct cmp_by_name{
    std::string name;
    cmp_by_name(const std::string& s): name(s) {}
    bool operator()(const Item& i){
        return i.name == name;
    }
};

struct cmp_by_iid{
    int iid;
    cmp_by_iid(const int& n): iid(n) {}
    bool operator()(const Item& i){
        return i.iid == iid;
    }
};

std::ostream& operator<<(std::ostream& os, const Item& item){
    return os << item.name << " - "
     << item.iid << " - "
     << item.value
     << std::endl;
}

std::istream& operator>>(std::istream& is, Item& item){
    std::string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    Item temp {name,iid,value};
    item = temp;
    return is;

}

template<typename T>
void print(T first, T last){
    while(first!=last){
        std::cout << *first << std::endl;
        ++first;
    }
}

void list_stuff(std::list<Item>& li){
        //Needs a predicate
    li.sort([](const Item& a, const Item& b){
                    return a.name < b.name;
                });
    print(li.begin(),li.end());

    li.sort([](const Item& a, const Item& b){
                    return a.iid < b.iid;
                });
    print(li.begin(),li.end());

    li.sort([](const Item& a, const Item& b){
                    return a.value < b.value;
                });
    li.reverse();
    print(li.begin(),li.end());

    li.insert(li.begin(),Item("horseshoe",99,12.34));
    li.insert(li.begin(),Item("Canon S400",9988,499.95));
    print(li.begin(),li.end());

    li.erase(std::find_if(li.begin(),li.end(), cmp_by_name("Pwefx")));
    li.erase(std::find_if(li.begin(),li.end(), cmp_by_name("horseshoe")));
    print(li.begin(),li.end());

    li.erase(std::find_if(li.begin(),li.end(), cmp_by_iid(4)));
    li.erase(std::find_if(li.begin(),li.end(), cmp_by_iid(6)));
    print(li.begin(),li.end());
}

void vector_stuff(std::vector<Item>& vi){
    std::sort(vi.begin(), vi.end(),
                [](const Item& a, const Item& b){
                    return a.name < b.name;
                }
    );

    print(vi.begin(),vi.end());
    std::sort(vi.begin(), vi.end(),
                [](const Item& a, const Item& b){
                    return a.iid < b.iid;
                }
    );
    print(vi.begin(),vi.end());

    std::sort(vi.begin(), vi.end(),
                [](const Item& a, const Item& b){
                    return a.value < b.value;
                }
    );
    std::reverse(vi.begin(), vi.end());
    print(vi.begin(),vi.end());

    vi.insert(vi.end(),Item("horseshoe",99,12.34));
    vi.insert(vi.end(),Item("Canon S400",9988,499.95));
    print(vi.begin(),vi.end());

    vi.erase(std::find_if(vi.begin(),vi.end(), cmp_by_name("Pwefx")));
    vi.erase(std::find_if(vi.begin(),vi.end(), cmp_by_name("horseshoe")));
    print(vi.begin(),vi.end());

    vi.erase(std::find_if(vi.begin(),vi.end(), cmp_by_iid(4)));;
    vi.erase(std::find_if(vi.begin(),vi.end(), cmp_by_iid(6)));;
    print(vi.begin(),vi.end());

    
};

int main()
try{
    
    std::vector<Item> vi;
    std::list<Item> li;
    std::ifstream file {"source.txt"};
    if(!file) throw std::runtime_error("Cant open file");
    Item i;

    while(file >> i){
        vi.push_back(i);
        li.push_back(i);
    }
    print(vi.begin(),vi.end());
    print(li.begin(),li.end());
    vector_stuff(vi);
    list_stuff(li);

    return 0;
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
    return -1;
}
catch (...) {
    std::cerr << "exception\n";
    return -2;
}