// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::sort
#include <vector>       // std::vector

typedef signed int              etg_tS32;
typedef unsigned  int              etg_tU32;
typedef char                    etg_tChar;
typedef unsigned int            etg_tUInt;

const int etg_test_cpp_aTestKeys[] = {
   -1, // nagative number
   3,
   5,
   10,
   12
};

const char* etg_test_cpp_aTestStrings[] = {
   "negative one",
   "three",
   "five",
   "ten",
   "twelve",
   "undefined enum aTest"
};
   etg_tS32 binarySearch(const etg_tS32 s32Array[], etg_tU32 u32Left, etg_tU32 u32Right, const etg_tS32 s32Val);
   const etg_tChar* etg_pcGetStringFromEnum(etg_tUInt uImax, const etg_tS32 aKeys[], const etg_tChar* aStrings[], etg_tS32 s32Val);

 /*const char* etg_pcGetStringFromEnumUsingLowerBound(const int uImax, const int aKeys[], const char *aStrings[], const int value) {
    std::vector<int> v(aKeys,aKeys + uImax);
    std::sort(v.begin(),v.end()); // if you provided a sorted array, this step will be removed !
    std::vector<int>::iterator it;
    it=std::lower_bound (v.begin(), v.end(), value);
    int index = it - v.begin();
    if((it != v.end()) && ( v.at(index) == value)){// recheck to make sure get right index
        return aStrings[index];
    }
    return aStrings[uImax];
}

//search function using binary algorithm
int binarySearch(const int arr[], int left, int right, const int value)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            return binarySearch(arr, left, mid - 1, value);
        return binarySearch(arr, mid + 1, right, value);
    }
    return -1;
}*/


// iterate from 0 .. (uImax-1) to find a fitting key and return corresponding string
// in case not found return string in index uImax
// requirement: number of aKeys is (uImax-1) and aStrings is uImax (one more for the "not found" status
// assumption: aKeys is sorted ascending with unsigned type size_t (32 / 64 bit) depending on arch
/*
const etg_tChar* etg_pcGetStringFromEnum(etg_tUInt uImax, const etg_tS32 aKeys[], const etg_tChar* aStrings[], etg_tS32 s32Val) {
	etg_tS32 s32Index = binarySearch(aKeys, 0, uImax-1, s32Val);
    if(s32Index == -1 ) return aStrings[uImax];
    return aStrings[s32Index];
}

const char* etg_pcGetStringFromEnumUsingBinarySearch(const int uImax, const int aKeys[], const char *aStrings[], const int value) {
    int index = binarySearch(aKeys, 0, uImax-1, value);
    if(index == -1 ) return aStrings[uImax];
    return aStrings[index];
}*/

int main () {
  int ETG_TEST_CPP_UITEST_MAX = sizeof(etg_test_cpp_aTestKeys)/(sizeof(int));
  int value = 4; /* negative one -1 */
  std::string text = etg_pcGetStringFromEnum(ETG_TEST_CPP_UITEST_MAX, etg_test_cpp_aTestKeys, etg_test_cpp_aTestStrings, value);
  std::cout << text << std::endl;
  text = etg_pcGetStringFromEnum(ETG_TEST_CPP_UITEST_MAX, etg_test_cpp_aTestKeys, etg_test_cpp_aTestStrings, value);
  std::cout << text << std::endl;
  return 0;
}


/**
 * binarySearch: search function using binary search algorithm
 *
 * @param s32Array value array
 * @param u32Left left index
 * @param u32Right right index
 * @param s32Val value need to search
 * @return index of matched item, -1 if not find value
 */
etg_tS32 binarySearch(const etg_tS32 s32Array[], etg_tU32 u32Left, etg_tU32 u32Right, const etg_tS32 s32Val)
{
    if (u32Right >= u32Left) {
        etg_tS32 u32Mid = u32Left + (u32Right - u32Left) / 2;
        if (s32Array[u32Mid] == s32Val)
            return u32Mid;
        if (s32Array[u32Mid] > s32Val)
            return binarySearch(s32Array, u32Left, u32Mid - 1, s32Val);
        return binarySearch(s32Array, u32Mid + 1, u32Right, s32Val);
    }
    return -1;
}


// iterate from 0 .. (uImax-1) to find a fitting key and return corresponding string
// in case not found return string in index uImax
// requirement: number of aKeys is (uImax-1) and aStrings is uImax (one more for the "not found" status
// assumption: aKeys is sorted ascending with unsigned type size_t (32 / 64 bit) depending on arch
const etg_tChar* etg_pcGetStringFromEnum(etg_tUInt uImax, const etg_tS32 aKeys[], const etg_tChar* aStrings[],const etg_tS32 s32Val) {
	etg_tS32 s32Index = binarySearch(aKeys, 0, uImax-1, s32Val);
    if(s32Index == -1 ) return aStrings[uImax];
    return aStrings[s32Index];
}



/*
#include <iterator>
#include <map>
#include <cstdint>

std::string  getStringFromEnum(std::map<int,std::string> Map, int value){
      return  Map.find(value)->second;
 }

int main(){
  std::map<int,std::string> CCA_OPCODE_Map = { // CCA_OPCODE ==
     { 0, "OPCODE_SET" },
     { 1, "OPCODE_GET" },
     { 2, "OPCODE_METHODSTART" },
     { 3, "OPCODE_UPREG" },
     { 4, "ET_INITIATE" },
     { 5, "OPCODE_RELUPREG" },
     { 6, "OPCODE_METHODABORT" },
     { 7, "OPCODE_METHODRESULT" },
     { 8, "OPCODE_ERROR" },
     { 9, "OPCODE_ABORTRESULT" },
     { 10, "OPCODE_METHODRESULTFIRST" },
     { 11, "OPCODE_METHODRESULTMIDDLE" },
     { 12, "OPCODE_METHODRESULTLAST" },
     { 13, "OPCODE_CLIENT_PORT_ACK" },
     { 14, "OPCODE_SERVER_PORT_ACK" },
     { 16, "OPCODE_INCREMENT" },
     { 17, "OPCODE_DECREMENT" },
     { 18, "OPCODE_PURESET" }
 };

  char buffer[100];
  sprintf(buffer,"Get string from enum by int value(%d) : %s ",5, getStringFromEnum(CCA_OPCODE_Map,5).data());
  printf("%s \n",buffer);
  printf("sizeof unsigned char = %d \n", sizeof(unsigned char));
  printf("sizeof unsigned int = %d \n", sizeof(unsigned int));
  printf("sizeof unsigned long = %d \n", sizeof(unsigned long));
  printf("sizeof unsigned long long = %d \n", sizeof(unsigned long long));
  printf("sizeof unsigned short = %d \n", sizeof(unsigned short));
  printf("sizeof int = %d \n", sizeof(int));


  int t = 0xFFFFFFFF;
  printf("%x , %d \n",t , t);
  std::cout << std::hex <<  t << std::endl;
  std::cout << std::dec <<  t << std::endl;
  std::cout << t << std::endl;
  return 0;
}
*/




/*
  std::cout << "Hello world \n" << std::endl;
 std::map<int,std::string> Enum_GestureEvent = { // Enum_GestureEvent == Enum_NAME
     { 6, "ET_ABORT" },
     { 7, "ET_DT_START" },
     { 5, "ET_END" },
     { 2, "ET_HOLD" },
     { 0, "ET_INITIATE" },
     { 3, "ET_MOVE" },
     { 9, "ET_None" },
     { 8, "ET_RAW_DATA" },
     { 4, "ET_REPEAT" },
     { 1, "ET_START" }
 };

 for(std::map<int,std::string>::iterator it = Enum_GestureEvent.begin(); it != Enum_GestureEvent.end(); it++ ){
    std::cout << it->first << "  " <<  it->second << std::endl;
 }
  char buffer[100];
  sprintf(buffer,"Get string from enum by value : %s : %d ", getStringFromEnum(Enum_GestureEvent,5).data(),5);
  printf("%s",buffer);


 #======================================================================#
# ARRAY CCA_OPCODE                                                     #
#       ------------------                                             #
#======================================================================#
ARRAY CCA_OPCODE = 0:OPCODE_SET
ARRAY CCA_OPCODE = 1:OPCODE_GET
ARRAY CCA_OPCODE = 2:OPCODE_METHODSTART
ARRAY CCA_OPCODE = 3:OPCODE_UPREG
ARRAY CCA_OPCODE = 4:OPCODE_RELUPREG
ARRAY CCA_OPCODE = 5:OPCODE_METHODABORT
ARRAY CCA_OPCODE = 6:OPCODE_STATUS
ARRAY CCA_OPCODE = 7:OPCODE_METHODRESULT
ARRAY CCA_OPCODE = 8:OPCODE_ERROR
ARRAY CCA_OPCODE = 9:OPCODE_ABORTRESULT
ARRAY CCA_OPCODE = 10:OPCODE_METHODRESULTFIRST
ARRAY CCA_OPCODE = 11:OPCODE_METHODRESULTMIDDLE
ARRAY CCA_OPCODE = 12:OPCODE_METHODRESULTLAST
ARRAY CCA_OPCODE = 13:OPCODE_CLIENT_PORT_ACK
ARRAY CCA_OPCODE = 14:OPCODE_SERVER_PORT_ACK
ARRAY CCA_OPCODE = 16:OPCODE_INCREMENT
ARRAY CCA_OPCODE = 17:OPCODE_DECREMENT
ARRAY CCA_OPCODE = 18:OPCODE_PURESET

 for(std::map<int,std::string>::iterator it = Enum_CCA_OPCODE.begin(); it != Enum_CCA_OPCODE.end(); it++ ){
    std::cout << it->first << "  " <<  it->second << std::endl;
 }



#include <map>
#include <stdio.h>
#include <iostream>

std::map<int,std::string> testEnum {
	{1,"tstElem1"},{-12345,"tstElem1"}
};

std::string getStringFromEnum(std::map<int,std::string> Map, int value){
	return Map.find(value)->second;
}


*/

