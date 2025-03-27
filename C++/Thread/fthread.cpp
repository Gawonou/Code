#include <iostream>
#include <thread>


void task1(){

    for ( size_t i = 0; i < 5; i++)
        std::cout << "Task 1 Etape " << i << std::endl;
    }



void task2(){
    for ( size_t i = 0; i < 5; i++)
        std::cout << "Task 2 Etape " << i << std::endl;
    }


int main(int argc, const char** argv) {
    std::thread t1(task1);
    std::thread t2(task2);
    if (t1.joinable() && t2.joinable()){
        t1.join();
        t2.join();
    }


    return 0;
}