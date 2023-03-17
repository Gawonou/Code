#include<iostream>

int main(){

const char message[] = "Demonstration arrry of char and pointers to char\n";
char text[] = "Good morning", name[] = "Bill!";
char *cPtr = "Hello";

std::cout << cPtr << " "  << name << std::endl
          << text << std::endl;
std::cout<< " The text \\" << text
         << " starts at address " << (void*)text
         << std::endl;
std::cout << text + 6 << std::endl;
cPtr = name;
std::cout << " This  is the " << *cPtr << " of "<< cPtr << std::endl;
*cPtr = 'k';
std::cout << " Bill cant  not " << cPtr << "!\n" << std::endl;
    return 0;
}