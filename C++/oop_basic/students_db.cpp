#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <exception>
#include <sqlite3.h>  // Bibliothèque SQLite pour les opérations sur la base de données

using namespace std;

// Classe pour les exceptions spécifiques aux étudiants
class StudentException : public exception {
private:
    string message;

public:
    StudentException(const string &msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Classe Student pour gérer les informations de chaque étudiant
class Student {
private:
    string firstName;
    string lastName;
    char middleInitial;
    float gpa;
    string currentCourse;
    int studentId;

public:
    Student(const string &fName, const string &lName, char mInitial, float gpaValue, const string &course, int id)
        : firstName(fName), lastName(lName), middleInitial(mInitial), gpa(gpaValue), currentCourse(course), studentId(id) {}

    void Print() const {
        cout << left;
        cout << setw(15) << "Nom : " << setw(10) << firstName << " " << middleInitial << ". " << setw(15) << lastName << endl;
        cout << setw(15) << "GPA : " << fixed << setprecision(2) << gpa << endl;
        cout << setw(15) << "Cours actuel : " << setw(15) << currentCourse << endl;
        cout << setw(15) << "ID étudiant : " << setw(10) << studentId << endl;
        cout << "----------------------" << endl;
    }

    // Méthode pour insérer l'étudiant dans la base de données SQLite
    void insertIntoDatabase(sqlite3* db) const {
        string sql = "INSERT INTO Students (FirstName, LastName, MiddleInitial, GPA, CurrentCourse, StudentID) VALUES ('" + 
                     firstName + "', '" + lastName + "', '" + middleInitial + "', " + to_string(gpa) + ", '" + currentCourse + "', " + to_string(studentId) + ");";

        char* errorMsg = nullptr;
        int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMsg);
        
        if (rc != SQLITE_OK) {
            string error = "Erreur lors de l'insertion dans la base de données: " + string(errorMsg);
            sqlite3_free(errorMsg);
            throw StudentException(error);
        } else {
            cout << "Insertion réussie pour " << firstName << " " << lastName << endl;
        }
    }
};

// Fonction pour lire les étudiants depuis un fichier
vector<Student> ReadStudentsFromFile(const string &filename, sqlite3* db) {
    ifstream file(filename);
    vector<Student> students;

    if (!file.is_open()) {
        throw StudentException("Erreur : impossible d'ouvrir le fichier " + filename);
    }

    string firstName, lastName, course;
    char middleInitial;
    float gpa;
    int studentId;

    try {
        while (file >> firstName >> lastName >> middleInitial >> gpa >> course >> studentId) {
            // Affichage des données lues pour débogage
            cout << "Données lues - Prénom : " << firstName
                 << ", Nom : " << lastName
                 << ", Initiale : " << middleInitial
                 << ", GPA : " << gpa
                 << ", Cours : " << course
                 << ", ID : " << studentId << endl;

            // Création d'un objet Student
            Student student(firstName, lastName, middleInitial, gpa, course, studentId);
            students.push_back(student);

            // Insertion dans la base de données
            student.insertIntoDatabase(db);
        }

        // Vérification d'erreur après la boucle de lecture
        if (file.bad()) {
            cerr << "Erreur lors de la lecture du fichier." << endl;
        } else if (!file.eof()) {
            cerr << "Erreur de format dans le fichier." << endl;
        }

    } catch (const exception &e) {
        cerr << "Erreur lors de l'ajout de l'étudiant : " << e.what() << endl;
    }

    file.close();
    return students;
}

// Fonction pour créer la table des étudiants dans la base de données
void createTable(sqlite3* db) {
    const char* sqlCreateTable = "CREATE TABLE IF NOT EXISTS Students ("
                                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                 "FirstName TEXT NOT NULL, "
                                 "LastName TEXT NOT NULL, "
                                 "MiddleInitial CHAR(1), "
                                 "GPA REAL, "
                                 "CurrentCourse TEXT, "
                                 "StudentID INT);";

    char* errorMsg = nullptr;
    int rc = sqlite3_exec(db, sqlCreateTable, nullptr, nullptr, &errorMsg);

    if (rc != SQLITE_OK) {
        string error = "Erreur lors de la création de la table: " + string(errorMsg);
        sqlite3_free(errorMsg);
        throw StudentException(error);
    }
}

int main() {
    cout << "Gawonou ..." << endl;
    sqlite3* db;
    int rc = sqlite3_open("students.db", &db);  // Ouvre la base de données SQLite

    if (rc) {
        cerr << "Erreur lors de l'ouverture de la base de données: " << sqlite3_errmsg(db) << endl;
        return rc;
    }

    try {
        createTable(db);  // Crée la table des étudiants
        string filename = "../data/students.txt";  // Assurez-vous que ce chemin est correct
        vector<Student> students = ReadStudentsFromFile(filename, db);  // Lit les étudiants et les insère dans la base de données

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

    sqlite3_close(db);  // Ferme la base de données SQLite
    return 0;
}
