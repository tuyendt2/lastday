#include <iostream>
#include <string>

using namespace std;

class Test{
public:
   /** Test(){
        cout << "default constructor" << endl;
    }; **/
/**    Test(int _tuoi, string _name ){
        name = _name;
        tuoi = _tuoi;
        cout << " constructor " << tuoi <<  " " << name << endl;
        cout << " constructor " << tuoi <<  " " << name << endl;
        run();
    } **/
    int run(){
        cout << "call tinhMethod " << tuoi << "  " << name << endl;
    }
    int tuoi;
    string name;
};

int main(){
    Test test{10,"ahihi"};
    test.run();
    return 0;
}

