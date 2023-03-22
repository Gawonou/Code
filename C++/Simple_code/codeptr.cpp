#include <iostream>

 // void pointer can point to any data type

 void print(void* ptr, char type){
      switch(type){
        case 'i': std::cout<< *((int*)ptr); break;
        case 'c': std::cout<< *((char*)ptr); break;

      }
      
    }

int main(){


    int y{5};
    int* yptr{nullptr};

    yptr = &y;

    int arr[5] = {1, 2, 3,4, 5};
    int arr1[]{12, 23, 34, 45, 56};


    std::cout<< "The adresse of y " << &y  << std::endl;
    std::cout<< "The value of yptr " << yptr  << std::endl;
    std::cout<< "The  value of y " << y  << std::endl;
    std::cout<< "The value of  yptr " << * yptr  << std::endl;

    int arr2[4] = {1, 2, 3,5};
    int *arr5  = new int[5];
    int* ptr_arr{nullptr};

    ptr_arr = arr;
    

    for (size_t i = 0; i < 4; ++i ){
        std::cout << *(arr + i) << std::endl;
        
    }
    std::cout << arr << std::endl;
    delete [] arr5;
     
  return 0;
}