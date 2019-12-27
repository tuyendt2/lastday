#include <iostream>
using namespace std ;


class A {
public:
    A(){
    static int s = 0;
    cout << "s = "<< s++ << endl;
    cout << "call constructor A " << ++count << " time(s)" << endl;
    }
    static int count;
};
int A::count = 0;

class B : public A {
public:
    B(){
    cout << "call constructor B " << endl;
    }
};

void func(const int & a){
 cout << "a = " << a << endl;
}
#include <iostream>
using namespace std;

int main() {
    A a;
    B b;
    int d =10;
    int *c = &d;
    func(d);
    system("DATE");
    return 0;
}
