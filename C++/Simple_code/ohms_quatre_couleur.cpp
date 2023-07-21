#include <iostream>
#include <map>
#include <string>

using namespace std;

// Fonction qui calcule la valeur de la résistance à partir des 4 bandes
double calculerResistance(int b1, int b2, int b3, int b4) {
    // Tableau des valeurs associées aux couleurs des bandes
    map<string, int> couleurs {
        {"noir", 0},
        {"marron", 1},
        {"rouge", 2},
        {"orange", 3},
        {"jaune", 4},
        {"vert", 5},
        {"bleu", 6},
        {"violet", 7},
        {"gris", 8},
        {"blanc", 9}
    };

    // Calcul de la valeur de la résistance en ohms
    int valeur = (couleurs[to_string(b1)]*10 + couleurs[to_string(b2)]) * pow(10, couleurs[to_string(b3)]);

    return valeur;
}

int main() {
    // Exemple d'utilisation de la fonction pour une résistance de couleurs marron-noir-rouge
    // avec une tolérance de +/- 5%
    int b1 = 1; // Marron
    int b2 = 0; // Noir
    int b3 = 2; // Rouge
    int b4 = -1; // Pas de tolérance

    double valeur = calculerResistance(b1, b2, b3, b4);
    cout << "La résistance vaut : " << valeur << " ohms" << endl;

    return 0;
}
