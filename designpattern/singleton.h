#include <string>
using namespace std;
class SingletonExample {

private:
    static SingletonExample * instance;
    static SingletonExample objectInstance;
    SingletonExample(){}
public:
    static SingletonExample* createInstance(){
        if(instance == NULL){
            instance = new SingletonExample();
        }
        return instance;
    }
    void run(){
        cout << "SingletonExample RUN" << endl;
    }
    //SingletonExample(const SingletonExample&) = delete;
    //SingletonExample(SingletonExample&&) = delete;
    //SingletonExample& operator=(const SingletonExample&) = delete;
    //SingletonExample& operator=(SingletonExample&&) = delete;
};



class SingletonUsingStaticInstance {
public:
    static SingletonUsingStaticInstance& createInstance(){
        static SingletonUsingStaticInstance instance;
        return instance;
    }
    void run(){
        cout << "SingletonUsingStaticInstance RUN" << endl;
    }
    //static SingletonUsingStaticInstance * instance;
private:
    SingletonUsingStaticInstance(){}
};



class Singleton {
public:
    static Singleton* createInstance(){
        if(instance != NULL)
        return instance;
    }
    void run(){
        cout << "Singleton RUN" << endl;
    }
    //static SingletonUsingStaticInstance * instance;
private:
    static Singleton *instance;
    Singleton(){}
};
