#include <iostream>
#include "singleton.h"
using namespace std;
SingletonExample* SingletonExample::instance = NULL;
SingletonExample SingletonExample::objectInstance = SingletonExample() ;
Singleton* Singleton::instance = new Singleton();
int main(){
    static_cast<SingletonUsingStaticInstance*>(&SingletonUsingStaticInstance::createInstance())->run();
    SingletonExample * singletonExample = SingletonExample::createInstance();
    singletonExample->run();

    //SingletonUsingStaticInstance * instance = &SingletonUsingStaticInstance::createInstance();
    return 0;
}
