#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>   // Pour les codes d'erreur


typedef struct {
    char lname[50];
    char fname[50]; 
    int age;
    char grade;
} Student;



void gestion_erreur(const char* message) {
    perror(message); // Affiche un message d'erreur lié à errno
    exit(EXIT_FAILURE); // Termine le programme en cas d'erreur
}


void ApplyStudentDisplay(Student* students, int size, void (*func)(const Student*)){
    for(int i= 0; i < size; i++){
        func(&students[i]);
    }
}


void displayStudent(const Student* student){
    printf("Nom : %s, Prenom : %s, Age : %d, Grade : %c \n", student->lname, student->fname, student->age, student->grade);
}



Student* allocateStudentArray(int size){
    Student* students = (Student*) malloc(size * sizeof(Student));
    if (students == NULL){
        printf("Erreur d'allocation de memoire ...\n");
        exit(1);
    }

    return students;
}

void inputStudentData(Student* student, const char* lname, char* fname, int age, float grade){
    errno_t result1 = strcpy_s(student->fname, sizeof(student->fname), fname);
    errno_t result2 = strcpy_s(student->lname, sizeof(student->lname), lname);
    if (result1 != 0 || result2 != 0 ){
        gestion_erreur("Erreur de copie ...\n");
        exit(1);
    }
    student->age = age;
    student->grade = grade;
}

int readfilestudent(const char* filename, Student* students, int maxSize){
 FILE* file;
 errno_t  err = fopen_s(&file, filename, "r");
 if (err != 0 || file == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s. Code d'erreur: %d\n", filename, err);
    return -1;
 }
  
    char buffer[256];

   // Lire et ignorer la première ligne (commentaire)
    fgets(buffer, sizeof(buffer), file);
    //printf("%s",buffer);

  int i = 0;
  char fname[50];
  char lname[50];
  int age;
  char grade;
   
    while (fgets(buffer, sizeof(buffer), file) != NULL && i < maxSize) {
     //printf("%d, %s ...\n", i, buffer);
    if(sscanf(buffer, "%49[^,], %49[^,], %d, %c", fname, lname, &age, &grade) == 4){
        //printf("%d", age);
        inputStudentData(&students[i], fname, lname, age, grade);
     i++;
    } else {
            printf("Erreur de format dans la ligne : %s\n", buffer);
        }
    }
    
    fclose(file);

 return i;

}


int main(){
    int studentMaxCount = 50;
    Student* students = allocateStudentArray(studentMaxCount);


    int actualStudentCount = readfilestudent("data/person_info_50.txt", students, studentMaxCount);
    printf("%d \n", actualStudentCount);
    if (actualStudentCount <= 0){
        printf("%d\n", actualStudentCount);
        gestion_erreur("Aucun etudiant lu depuis le fichier ....");
        free(students);

    }
    printf("La liste des etudiants avant initial");
    ApplyStudentDisplay(students, studentMaxCount, displayStudent);


    return 0;

}