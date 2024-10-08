#include "vecteur.h"

VecteurEtudiants* creerVecteur(int capacite){
    VecteurEtudiants* vecteur = (VecteurEtudiants*)malloc(sizeof(VecteurEtudiants));
    vecteur->etudiants = (Etudiant*)malloc(capacite* sizeof(Etudiant));
    vecteur->taille = 0;
    vecteur->capacite = capacite;
    return vecteur;
}


void libererEtudiant(Etudiant * etudiant){
   free(etudiant->nom);
   free(etudiant->prenom);
}


void libererVecteur(VecteurEtudiants* vecteur){
    for(size_t i = 0; i < vecteur->taille; i++)
        libererEtudiant(&vecteur->etudiants[i]);
    
    free(vecteur->etudiants);
    free(vecteur);
}