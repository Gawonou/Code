#include<string>

class Car{
    private:
        long nr;
        std::string producer;
    public:
        Car(long n = 0L, const std::string& prod = "" );
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

class PassCar: public Car {
    public:
        PassCar(const std::string& tp, bool sd, int n = 0, const std::string& h = "");
        const std::string& getType() const { 
            return passCarType;
        }
    private:
    std::string passCarType;
    
};
