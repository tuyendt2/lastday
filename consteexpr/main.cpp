#include <iostream>
constexpr int product(int x, int y)
{
	return (x * y);
}
class Test{
public:
    Test(int a, int b){
        member1 = a;
        member2 = b;
    }
    int tong (int a, int b) const{
       member1 += a;
       member2 += b;
       return a + b;
    }

   void tong (int a, int b) {
       member1 += a;
       member2 += b;
    }

    void out(){
        std::cout << "member1 " << member1 << std::endl;
        std::cout << "member2 " << member2 << std::endl;
    }
protected:
    int mutable member1;
    int mutable member2;
};

int main()
{
    Test test(10,20);
    test.out();
    test.tong(10,100);
    test.out();
    int usigned =  ~0x80000000;
    short int result = usigned;
    std::cout << "usigned = " << usigned << "result " << result << std::endl;
}
