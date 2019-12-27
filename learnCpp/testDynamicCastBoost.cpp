#include <iostream>
#include <memory>
#include <boost/shared_ptr.hpp>
using namespace std;

class Base {
public:
   int value;
   virtual void run(){
      std::cout << "run base " << std::endl;
   }
};


class Drived : public Base  {
public:
   virtual void run(){
       std::cout << "run drived " << std::endl;
   }
};

class Drived_Drived : public Drived{
public:
   void run (){
   std::cout << "run drived drived " <<std::endl;
}

};


int main(){

   Drived_Drived * objectShared = new Drived_Drived();
   Drived *  objectDrived = new Drived();
   ::boost::shared_ptr<Drived_Drived> drivedSharedPtr;
   ::boost::shared_ptr<Drived> sharedPtr;
   ::boost::shared_ptr<Base> baseSharedPtr(objectDrived);
   ::boost::shared_ptr<Base> baseSharedPtr_2(objectShared);
   std::cout << "Hello World ! " << std::endl;
    sharedPtr = ::boost::dynamic_pointer_cast<Drived>(baseSharedPtr);
   sharedPtr->run();
    drivedSharedPtr =  ::boost::dynamic_pointer_cast<Drived_Drived> (baseSharedPtr_2);
    drivedSharedPtr->run();
   return 0;
}
