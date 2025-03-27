#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <format>
#include <vector>


void line(){
    std::cout << "\n==========================================" << std::endl;
}


int const  N = 10;


int main(int argc, const char** argv) {
    
    std::array<int,  N> arr {1,3,5,64,11,25,43,32,9,87};

    line();
    std::string message = std::format("Tableau Initial {}", 1);
    std::cout << message << std::endl;

    for (int ar : arr){
        std::cout << ar << "  ";
    }
    line();

    std::cout << "Premier Elt: " << arr.front() <<  ", Dernier Elt : " << arr.back() << std::endl;
    
    line();
    std::cout << " Liste triee ";
    std::sort(arr.begin(), arr.end());
    for(int ar : arr){
        std::cout << ar << "  ";
    }

    line();
    int elementRecherche = 32;
    auto it = std::find(arr.begin(), arr.end(), elementRecherche);
    
    if (it != arr.end()){
        std::cout << "Element " << elementRecherche   << " a ete trouve a l index : "
                << std::distance(arr.begin(), it) << std::endl;
            }
    else {
        std::cout <<  elementRecherche  << " non trouve, " << std::endl;
    } 
    

    int somme = std::accumulate(arr.begin(), arr.end(), 0);
    message =  std::format("La somme des element est : {} ", somme);
    
    std::cout << message << std::endl;


    struct Personne {
    std::string nom;
    std::string prenom;
    int age;
};


    // Créer un tableau de personnes
    std::vector<Personne> personnes = {
        {"Dupont", "Jean", 25},
        {"Martin", "Marie", 20},
        {"Durand", "Pierre", 30},
        {"Leroy", "Sophie", 20}
    };

    // Utiliser std::find_if pour trouver une personne de 20 ans
    auto its = std::find_if(personnes.begin(), personnes.end(), [](const Personne& p) {
        return p.age == 20;
    });

    // Afficher la personne trouvée
    if (its != personnes.end()) {
        std::cout << "Personne de 20 ans trouvee : " << its->prenom << " " << its->nom << std::endl;
    } else {
        std::cout << "Aucune personne de 20 ans trouvee." << std::endl;
    }

    // Utiliser std::accumulate pour calculer la somme des âges
    int sommeDesAges = std::accumulate(personnes.begin(), personnes.end(), 0, [](int sum, const Personne& p) {
        return sum + p.age;
    });

    // Afficher la somme des âges
    std::cout << "Somme des ages : " << sommeDesAges << std::endl;




    return 0;

   
}

