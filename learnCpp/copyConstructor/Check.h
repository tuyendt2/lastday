#include <iostream>
using namespace std;
class CheckCopyConstructorWork {
	public: 
	CheckCopyConstructorWork(int number){
		cout << "CheckCopyConstructorWork constructor is called ! " << number;
	}
	CheckCopyConstructorWork(const CheckCopyConstructorWork &target);
        CheckCopyConstructorWork & operator = (const CheckCopyConstructorWork &target);
	int number;
	virtual int square();
};
