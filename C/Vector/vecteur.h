#ifndef VECTEUR_H
#define VECTEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  float note;
  int coefficient;
}NoteMath;

typedef struct{
  float note;
  int coefficient;
}NoteInformatique;

typedef struct{
  float note;
  int coefficient;
}NoteFrench;


typedef struct{
    NoteMath math;
    NoteFrench francais;
    NoteInformatique Informatique;
} Notes;


typedef struct {
    char* nom;
    char* prenom;
    char sexe;
    Notes notes;
    char grade;

} Etudiant;

typedef struct {
    Etudiant* etudiants;
    int capacite;
    int taille;
} VecteurEtudiants;



VecteurEtudiants* creerVecteur(int capacite);
void libererVecteur(VecteurEtudiants* vecteur);
int ajouteEtudiant(VecteurEtudiants vecteur, Etudiant etudiant);
int suprimeEtudiant(VecteurEtudiants vecteur, int index);
Etudiant* rechercheEtudiantParGrade(VecteurEtudiants vecteur, char grade);
int lireEtudiantsDepuisFichier(const char *file, VecteurEtudiants* vectueur);
char calculerGrade(float moyenne);
void afficherEtudiants(VecteurEtudiants vecteur);
float calculerMoyenne(Notes notes);





#endif // !VECTEUR_H
