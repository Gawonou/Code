#include <iostream>
#include <ostream>
#include <string>
#include <list>

//using namespace std;

class tload{
    public:
        std::string Name;
        int SubCount;

        tload(std::string name, int count){
            Name = name;
            SubCount = count;
        }   
        bool operator==(const tload& over) const {
            return this->Name == over.Name && this->SubCount == over.SubCount;
    }
};

std::ostream& operator<<(std::ostream& Cout, tload& over){
    Cout << "Name: " << over.Name << std::endl;
    Cout << "SubCount: " << over.SubCount <<std::endl;

    return Cout;
}



class Collection {
    public:
    std::list<tload> ltload;

    void operator+=(const tload& over){
        this->ltload.push_back(over);
    }
    
   void operator-=(tload& over){
       this->ltload.remove(over);
    }
};

std::ostream& operator<<(std::ostream& Cout, Collection& cols){
    for(tload col : cols.ltload){
        Cout << col << std::endl;
    }
    return Cout;
}


int main() {
    tload *Ov = new tload("Gawonou", 40);
    tload *Ov1 = new tload("Kokou", 38);

    std::cout << *Ov << *Ov1;

    Collection cols;
    cols += *Ov;
    cols += *Ov1;
    std::cout << " =================" <<std::endl;
    std::cout << cols;

    
    cols -= *Ov1;
    std::cout << " =================" <<std::endl;
    std::cout << cols;


    delete Ov;
    delete Ov1;
    return 0;
}