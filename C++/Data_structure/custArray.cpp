#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>

using namespace std;

template<typename T>
class CustArray {
    private:
        T* data;
        size_t  size;
        size_t  capacity;

        void expandCapacity(){
            if (size >= capacity){
                capacity = (capacity == 0) ? 1 : capacity * 2;
                T* NewData = new T[capacity];
                for(size_t i = 0; i < size; ++i){
                    NewData[i] = data[i];
                }

                delete [] data;
                data = NewData;
            }
        }    
    public:
        CustArray(size_t initialSize = 10): size(0), capacity(initialSize){
            data = new T[capacity];
        }

        CustArray(initializer_list<T> list): size(list.size()), capacity(list.size()){
            data = new T[capacity];
            size_t i = 0;

            for(const T& val: list){
                data[i++] = val;
            }
        }


        ~CustArray(){
            delete[] data;
        }
        T* begin() { return data; }
        T* end() { return data + size; }
        CustArray(const CustArray& arr){
            size = arr.size;
            capacity = arr.capacity;
            data = new T[capacity];
            for(size_t i = 0; i < size; ++i){
                data[i] = arr.data[i];
            }
        }

    CustArray& operator=(const CustArray& arr){
        if(this != &arr){
            delete[] data;

        size = arr.size;
        capacity = arr.capacity;
        data = new T[capacity];
        for(size_t i = 0; i < size; ++i)
            data[i] = arr.data[i];
        }
        
        return *this;
    }


    T& operator[](size_t index ){

            if(index <  0 || index > size ){
                throw out_of_range("Index hors limites !");
            } 
           return data[index];
        }

        size_t  getSize() const {
            return size;
        }

        void push_back( const T& value ){
            expandCapacity();
            data[size++] = value;
        }

        void insert(size_t index,  const T& value){
            if(index > size){
                throw out_of_range("Index hors limites");
            }
            expandCapacity();
            for(size_t i = size; i > index; --i){
                data[i] = data[i-1];
            }
            data[index] = value;
            ++size;
        }

        // Supprimer un élément à une position donnée
    void remove(size_t index) {
        if (index >= size)
            throw out_of_range("Index hors limites !");
        
        for (size_t i = index; i < size - 1; ++i)
            data[i] = data[i + 1];

        --size;
    }


        void resize(size_t newSize){
            if(newSize > capacity) {
                capacity = newSize;
            T* newData = new T[capacity];
                for(size_t i = 0; i < size; ++i){
                    newData[i] = data[i];
                }
                
            delete[] data;
            data = newData;
            }
            size = newSize;
        }


    int find(const T& value) const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == value)
                return i;
        }
        return -1;
    }
   
    void sortArray(){
        sort(data, data + size);
    }

    void afficher() const {
        for (size_t i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

};


int main(int argc, const char** argv) {

    try
    {
        CustArray<int> tab;

        tab.push_back(5);
        tab.push_back(2);
        tab.push_back(8);
        tab.push_back(3);
        tab.afficher(); // 5 2 8 3

        // Insertion d'un élément
        tab.insert(1, 10);

        tab.afficher();



    }
    catch (const std::exception&e)
    {
        cout << "Erreur :" << e.what() << endl;
    }
    return 0;
}