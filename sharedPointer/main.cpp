#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <map>
#include <iostream>



class A {
int FunctionA(){ return 1;}
void FunctionA(int a){ std::cout << a;};
};

std::map<int,std::shared_ptr<int>> m_map;
std::map<std::shared_ptr<int>,int> m_map2;

std::shared_ptr<int> createSharedPointer(std::shared_ptr<int>  &a){

  return a;
}

int main(){

int a =10;

int &x = a;

int c = 10;

int &b = c;

b = 12;

a =1;

std::cout << a << b << x << c;

std::shared_ptr<int> ptr = std::make_shared<int>(a);

std::shared_ptr<int> ptr1 = createSharedPointer(ptr);

std::shared_ptr<int> ptr2 = createSharedPointer(ptr);

if(ptr2 == ptr){
std::cout << "TRUE\n";
}else {
std::cout << "FALSE \n";
}

m_map.insert({1,ptr});
m_map.insert({2,ptr2});

m_map2.insert({ptr,1});
m_map2.insert({ptr2,2});
std::map<std::shared_ptr<int>,int>::iterator it = m_map2.find(ptr2);
if (it != m_map2.end() ){
std::cout << "compare true " << it->second;
}else{
std::cout << "compare false";

}
}
