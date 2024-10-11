#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <iomanip>  
#include <exception> 
#include <string>

using namespace std;

class StudentException : public exception {
private:
    string message;

public:
    StudentException(const string &msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Student {
private:
    string firstName;
    string lastName;
    char middleInitial;
    float gpa;
    string currentCourse;
    const int studentId;

public:
    Student(const string &fName, const string &lName, char mInitial, float gpaValue, const string &course, int id) 
    : firstName(fName), lastName(lName), middleInitial(mInitial), gpa(gpaValue), currentCourse(course), studentId(id) {}

    void Print() const {
        cout << left;  
        cout << setw(15) << "Nom : " << setw(10) << firstName << " " << middleInitial << ". " << setw(15) << lastName << endl;
        cout << setw(15) << "GPA : " << fixed << setprecision(2) << gpa << endl;
        cout << setw(15) << "Cours actuel : " << setw(15) << currentCourse << endl;
        cout << setw(15) << "ID Etudiant : " << setw(10) << studentId << endl;
        cout << "----------------------" << endl;
    }
};

vector<Student> ReadStudentsFromFile(const string &filename) {
    ifstream file(filename);
    vector<Student> students;

    if (!file.is_open()) {
        throw StudentException("Erreur : impossible d'ouvrir le fichier " + filename);
    }

    string firstName, lastName, course;
    char middleInitial;
    float gpa;
    int studentId;
    int lineCount = 0;

    try {
        while (file >> firstName >> lastName >> middleInitial >> gpa >> course >> studentId) {
            lineCount++;
            // Affichage des données lues pour débogage
            cout << "Ligne " << lineCount << " : Donnees lues - Prenom : " << firstName 
                 << ", Nom : " << lastName 
                 << ", Initiale : " << middleInitial 
                 << ", GPA : " << gpa 
                 << ", Cours : " << course 
                 << ", ID : " << studentId << endl;

            students.emplace_back(firstName, lastName, middleInitial, gpa, course, studentId);
        }

        // Vérification d'erreur après la boucle de lecture
        if (file.bad()) {
            cerr << "Erreur lors de la lecture du fichier." << endl;
        } else if (!file.eof()) {
            cerr << "Erreur de format dans le fichier à la ligne " << lineCount + 1 << endl;
        }

    } catch (const exception &e) {
        cerr << "Erreur lors de l'ajout de l'étudiant : " << e.what() << endl;
    }

    file.close();
    return students;
}

int main() {
    cout << "Gawonou ..." << endl;
    try {
        string filename = "../data/students.txt";  // Assurez-vous que ce chemin est correct
        vector<Student> students = ReadStudentsFromFile(filename);
        
        if (students.empty()) {
            throw StudentException("Aucun étudiant n'a été trouvé dans le fichier " + filename);
        } else {
            for (const auto &student : students) {
                student.Print();
            }
        }
    } catch (const StudentException &e) {
        cerr << e.what() << endl;
    } catch (const exception &e) {
        cerr << "Une erreur inattendue s'est produite : " << e.what() << endl;
    }

    return 0;
}
