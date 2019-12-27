#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
int main(){
    /*
    int a =100, b =1000;
    string c = "Hello world ! ";
    std::stringstream stream;
    stream <<  a << b << c << endl;
    //stream.str(std::string());
    stream << std::hex << a << endl << std::oct << a << endl;
    cout << stream.str() << endl;

    a =12345;
    cout << std::to_string(a).c_str() << endl;
    int d = 123456;
    string f = "ahihi";
    string ret  = f + "ada sdas asd " + to_string(a);
    cout << "ret = " << ret << endl;
    float t = 17.50;


    char str[100];
    sprintf(str, "Value of %d = 0X%04X%% ", 100,100);
    const char * str1 = str;
    std::string a = str;
    cout << "a = " << a << a.length() << "str size = " << sizeof(str);
    a.c_str();

    bool  a = false;
    std::string isActiveString = a? "true":"false";
    std::string f = "sdfsd sdfds sfsd " + isActiveString + "   sdf";
    cout <<f <<endl;*/

    std::stringstream stream ;
    stream << std::setw(4) << std::setfill('0') << std::dec << 0x0E ;
    cout << stream.str() << endl;
    stream.str(std::string());
    stream << std::setw(8) << std::dec << 0xF  ;
    cout << stream.str()<<endl;
    std::cout << "default fill: " << std::setw(20) << 42 << '\n'
              << "setfill('*'): " << std::setfill('*')
                                  << std::setw(10) << 42 << '\n';
    printf("%10s","fsdfsdf \n");
    int a =15;
    int b =a;
    printf("ahihi : %x, %p, %*x , %x %s \n", a,&a,a,&a,a);
    printf("ahihi : %x, %p, %*x , %x  %s \n", b,&b,b,&b,b);
   //printf("%0.8d",100);


}


/*
#include <iostream>
#include <map>
using namespace std;

int main()
{
    // declaration of map container
    map<char, int> mymap;
    mymap['a'] = 1;
    mymap['b'] = 2;
    mymap['c'] = 3;

    // using begin() to print map
    for (auto it = mymap.begin();
         it != mymap.end(); ++it)
        cout << it->first << " = "
             << it->second << '\n';
    std::map<char,int>::const_iterator it;
    it = mymap.find('c');
    if(it != mymap.end()){
        cout << "do right " << endl;
    }else {
        cout << "do wrong " << endl;
    }
    it = mymap.end();
    cout << it->first;
    return 0;
}*/

