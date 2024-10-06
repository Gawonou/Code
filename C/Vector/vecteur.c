#include "vecteur.h"

VecteurEtudiants* creerVecteur(int capacite){
    VecteurEtudiants* vecteur = (VecteurEtudiants*)malloc(sizeof(VecteurEtudiants));
    vecteur->etudiants = (Etudiant*)malloc(capacite* sizeof(Etudiant));
    vecteur->taille = 0;
    vecteur->capacite = capacite;
    return vecteur;
}
