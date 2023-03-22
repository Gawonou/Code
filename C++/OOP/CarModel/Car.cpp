#include <string>
#include <iostream>


class Car{
    private:
        long nr;
        std::string producer;
    public:
        Car(long n = 0L, const std::string& prod = "" ){
            this->producer = prod;
            this->nr = n;
        };

        ~Car(){}

        long getNr(void) const {
            return  nr;
            }
        void setNr(long n) {
            nr = n;
        }

        const std::string& getProg() const{
            return producer;
        }

        void setProd(const std::string& p){
            producer = p;
        }

        void display(void) const;
};

void Car::display() const {
    std::cout << "Producer : " << producer << std::endl;
    std::cout << "nomber : "  << nr << std::endl;
}



class PassCar: public Car {
    public:
        PassCar(const std::string& tp, bool sd, int n = 0, const std::string& h = ""):
        Car(n, h), passCarType(tp), sunRoof(sd){};
        const std::string& getType() const { 
            return passCarType;
        }
        void setType(const std::string s) {
            passCarType = s;
        }
        bool getSunRoof()const {
            return sunRoof;
        }

        void setSunRoof(bool b) {
            sunRoof = b;
        }

        void display()const;

        ~PassCar(){}

    private:
    std::string passCarType;
    bool sunRoof;
};

void PassCar::display() const {
    Car::display();
    std::cout << "Type: "<< passCarType << std::endl;
    std::cout << "Roof: "  << sunRoof << std::endl;
}


int main(){
    
    const PassCar bentle("Bentle", false,  3421, "VM");
    bentle.display();

    std::cout << "=============================== " << std::endl;


    const PassCar Carbrio("RAV", true);
    Carbrio.display();
    return 0;
}