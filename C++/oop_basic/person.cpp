#include <iostream>
#include <memory>
#include <vector>
#include <functional>


class Person {
protected:
    std::string name;
public:
 Person(const std::string& name):name(name){};
 virtual ~Person() = default;

 virtual void showInfo() const {
    std::cout << "Nom : " << name  << std::endl;
    }
};

class Student: public Person {
private:
    int studentID;
public:
    Student(const std::string& name, int id): Person(name), studentID(id){}
    void showInfo() const override{
        std::cout << "Nom : " << name  << ", ID Etudiant :" << studentID << std::endl;
    }

};


class Teacher : public Person {
private:
    std::string subject;
public: 
    Teacher(const std::string& name, const std::string& subject ):Person(name), subject(subject){}

    void showInfo() const override{
        std::cout << "Nom : " << name  << ", Matiere :" << subject << std::endl;
    }

};

void applyToPerson(const std::vector<std::shared_ptr<Person>>& persons, const std::function<void (const std::shared_ptr<Person>&)>& func){
    for (const auto& person : persons){
         func(person);
        }
    }


int main(){
    
    Student* studentpr = new Student("Gawonou", 13000);
    studentpr->showInfo();
    delete studentpr;
     
    return 0;
}