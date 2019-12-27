#include <iostream>
#include <thread>
using namespace std;
  //This function will be called from a thread

  void call_from_thread() {
      std::cout << "Hello, World" << std::endl;
  }

 int main() {
     //Launch a thread
    thread t1(call_from_thread);

     //Join the thread with the main thread
    t1.join();

    return 0;
}
