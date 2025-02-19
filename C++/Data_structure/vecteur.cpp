#include <iostream>
#include <iostream>


template< typename T>
class Vector {
    private:
        T* arr;
        int capacity;
        int sise;

        void resize(int newCapacity){
            T* newArr = new T[newCapacity]

            for(int i = 0; i < size; i++){
                newArr[i] = arr[i];
            }

            delete[] arr; 
            arr = newArr;
            capacity = newCapacity;
        } 
    public:
    Vector(): arr(new T[1]), capacity(1), size(0){}{}

    ~Vector(){
        delete[] arr;
    }



    
} 