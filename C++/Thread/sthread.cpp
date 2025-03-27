#include<iostream>
#include<thread>
#include<mutex>


std::mutex mtx;
int shared_data = 0;


void increment_size(){
    for(int i = 0; i < 100000; ++i){
        //mtx.lock();
        //++shared_data;
        //mtx.unlock();

        std::lock_guard<std::mutex> lock(mtx);
        ++shared_data;
    }
}


int main(int argc, const char** argv) {

    unsigned int n = std::thread::hardware_concurrency();
    std::cout << "\nNombre de coeurs logiques disponibles : " << n << std::endl;

   
    std::thread t1(increment_size);
    std::thread t2(increment_size);

    t1.join();
    t2.join();
    
    std::cout << "La valeur final de shared_data : " << shared_data << std::endl;
    std::cout <<  " ";
    
    return 0;
}