#include <iostream>
#include <windows.h>
#include <shlobj.h>
#include<format>


template <typename T> T add_values(T a, T b, T c){

    return a + b + c;

}

auto calcul_mean(auto a, auto b, auto c) {

    return ( a + b + c)/ 3.0;

}


int main(int argc, const char** argv) {
    
    int a{10}, b{20}, c{30};


    int add_val = add_values(a,b,c);
    auto calcul_m = calcul_mean(a,b,c);

    std::string reponse = std::format("La reponse est de add_values  est {}", add_val);
    std::string reponse1 = std::format("La reponse est de calcul_meam  est {}", calcul_m);
    
    std::cout << reponse << std::endl;
    std::cout << reponse1 << std::endl;
    
    return 0;
}
