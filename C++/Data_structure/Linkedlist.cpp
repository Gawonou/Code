#include <iostream>
#include <stdexcept>


using namespace std;

template<typename T> 
class LinkedList{
    private:
        struct Node {
            T data;
            Node* next;

            Node(const T& value):data(value), next(nullptr){}
        };
        Node* head;
        size_t size;
    public:

    LinkedList(): head(nullptr),size(0){}

    ~LinkedList() {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(const T& value ){
        Node newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        ++size;
    }

    void push_back( const T& value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
        } else{
            Node* temp = head;
            while (temp->next)
                temp = temp->next;

            temp->next = newNode;
        }
    ++size;
    }

    void pop_front(){
        if(!head)
            throw out_of_range("La liste est vide.");  
        Node* temp = head;
        head = head->next;
        delede temp;
        --size;
    }

    void pop_back(){
        if(!head)
            throw out_of_range("La liste est vide.")

        if(!head->next){
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;                                                    xt;
            delete temp->next;
            temp->next = nullptr;
        }
        --size;
    }

    void insert(const T& value, size_t index){
        if(index > size )
            throw out_of_range("Index hors limites.")

        if (index == 0)
            push_front(value);
    }
};

int main(int argc, const char** argv) {

     try
     {
        LinkedList<int> list;
     }
     catch (const std::exception& e)
     {
        cout << "Erreur :" <<  e.what() << endl;
     }




    return 0;
}