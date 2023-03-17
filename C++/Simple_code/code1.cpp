#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <utility>
#include <vector>
#include <map>
#include <set> 


void printmap(const std::map<int, int> &m){
    std::map<int, int>::const_iterator it;
    for(it = m.begin(); it != m.end(); ++it){
       std::cout<< it->first << " is present " << it->second << " times " << std::endl;
    }
}

int main(){

    const int N = 120;
    std::map<int, int> map1;
    std::vector<int> vec;
    for (unsigned int counter{1}; counter<= N; ++counter){
        int randomvalue = 1 + std::rand() % 20;
        std::cout << std::setw(10) << randomvalue;
        
        if (counter % 5 == 0) {
        std::cout << std::endl;
        
    }
    vec.push_back(randomvalue);
    }

    std::set<int> myset(vec.begin(), vec.end());

    for (int x : myset ) {
    unsigned int count = 0;
    for ( int i : vec){
        if ( i == x) {
         //std::cout << x << std::endl;  
          count++;
         }
      }

       map1.insert({x, count});
      
    }
    printmap(map1);
    return 0;
}