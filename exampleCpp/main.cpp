#include <iostream>
#include <iomanip>
typedef short unsigned int tU16;
typedef short unsigned int t_uint16;
int main (){
	
  t_uint16 x1 = 1, x2 = 2;
 unsigned  char x3 = 0, x4 = 1;
 t_uint16 result = 0;

 result = ((t_uint16)x3 << 8 | (t_uint16)(x4));
 
 result = (t_uint16)(x3 << 8) | (t_uint16)(x4);

 std::cout << sizeof((t_uint16)x3 << 8 | (t_uint16)(x2)) << std::endl;

 std::cout << sizeof((x3 << 8)) << std::endl;
 
 std::cout << sizeof(result) << std::endl; 
 
/*     unsigned char x1 = 2, x2 = 1, c;
        tU16 ret = 0;
        int i = 0;
        tU16 s = 0;
        s = x1 | x2;
        std::cout << sizeof( x1 | ret) << std::endl;
//        s = x1 | ret;
        std::cout << "================"  << std::endl;
        s = (tU16)(x1 << 8) | (tU16)x2;
        std::cout << sizeof(x1 << 8) << std::endl;
        std::cout << "****************" << std::endl;
        std::cout << sizeof(i) << std::endl;
        std::cout << sizeof(s) << std::endl;
        std::cout << sizeof((((tU16)x1 << 8) | (tU16)x2)) << std::endl;;
        std::cout << std::hex << (((tU16)x1 << 8) | (tU16)x2) << std::endl;; */
 return 0;
}
