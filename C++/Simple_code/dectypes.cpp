#include<iostream>
#include<vector>


int somme(int a, int b){return a + b;}


int main(){

    int age = 25;
    double pi(3.14);
    char lettre{'A'};
    bool actif true;
    std::string nom = "Alice";
    

    std::vector<double> valeurs {1.5, 2.3, 3.7};
    auto  premier = valeurs[0];

    dectype (somme(2,3)) resultat = somme(10,5);


    std::cout << "Premier element " << premier << std::endl;

    std::cout << "Resultat de la somme : " << resultat << std::endl;
}