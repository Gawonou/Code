#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype> // Pour isdigit
#include <utility>



class Adresse {

    private:
        std::string rue;
        std::string ville;
        std::string pays;
        std::string id;

    public:
        Adresse() : rue("Inconnue"), ville("Inconnue"), pays("Inconnu"), id("0000"){}
        Adresse(std::string r, std::string v, std::string p, std::string id){
            
            if (r.empty() || v.empty() || p.empty() || id.empty()  )
                  throw std::invalid_argument("L'adresse ne peut pas contenir un champ vide");
                
                
                    rue = std::move(r);
                    ville = std::move(v);
                    pays = std::move(p);
                    id = std::move(id);
                
        }


        friend std::ostream& operator <<(std::ostream& os, const Adresse& a) {
            os << a.rue  << ",  " << a.ville << ", " << a.pays << std::endl;
            return os;
        }


        const std::string& getRue() const {return rue;}
        const std::string& getVille() const {return ville;}
        const std::string& getPays() const {return pays;}
        const std::string& getId() const {return id;}



        void setRue( const std::string& r ) { rue = r; }
        void setVille( const std::string& v ) { ville = v; }
        void setPays( const std::string& p ) { pays =  p; }
        void setId( const std::string& id ) { pays =  id; }

};



class Personne {
    private:
    std::string nom;
    std::string prenom;
    std::string nas;
    Adresse* adresse;
    int age;
    std::string id;
    public:
    Personne() : nom("Inconnu"), prenom("Inconnu"), age(0), adresse(new Adresse()), 
                        nas("000-000-000"), id("0000"){}

    Personne(std::string n, std::string p, int a, Adresse* adr, std::string nss, std::string id):
            nom(std::move(n)), prenom(std::move(p)), age(0), adresse(nullptr), nas("000-000-000"), id("0000"){
                setAge(a);
                setAdresse(adr); 
                setNas(nss);
                setId(id);
            }


    virtual ~ Personne(){
        delete adresse;
    }
                        
    Personne(const Personne& pers)
            : nom(pers.nom), prenom(pers.prenom), age(pers.age), nas(pers.nas), id(pers.id){
            adresse = new Adresse(*pers.adresse); // Copie profonde
    }

    /*Presonne(const Personne& pers) {
        nom= pers.nom;
        prenom = pers.prenom;
        age = pers.age;
        nas = pers.nas;
        adresse = new Adresse(*pers.adresse);
    } */



    bool operator>(const Personne& pers) const {
        return age > pers.age;
    }


    Personne& operator=(Personne pers){
        std::swap(nom, pers.nom);
        std::swap(prenom, pers.prenom);
        std::swap(age, pers.age);
        std::swap(adresse, pers.adresse);
        std::swap(nas, pers.nas);
        std::swap(id, pers.id);

        return *this;

    }



    bool operator==(const Personne& pers) const {
        return (id == pers.id && nom == pers.nom && prenom == pers.prenom && age == pers.age &&
                adresse->getRue() == pers.adresse->getRue() &&
                adresse->getVille() == pers.adresse->getVille() &&
                adresse->getPays() == pers.adresse->getPays() && nas == pers.nas);
    }

    // Opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const Personne& p) {
        os << "Nom : " << p.nom << "\nPrenom : " << p.prenom 
           << "\nAge : " << p.age << "\nAdresse : " << *p.adresse
           << "\nNAS : " << p.nas << "\n";
        return os;
    }
    
    void setAge( int a){
        if (a < 0)
            throw("Erreur: L age peut pas etre negatif");

        age = a;
    }


    void setNas(const std::string& nss) {
        
        if(!verifierFormatNas(nss)) {
            throw("Erreur: Format de Nas est incorrecte");

        }
        nas = nss;   
    }


    void setId(const std::string& id){
        if (id.length() == 0)
            throw("Erreur: Il doit avoir Id");
            this->id = id;
    }

    void setAdresse(Adresse* adr){
        if (!adr)
            throw("Erreur: Adresse ne doit pas etre null");

            delete adresse;
            adresse = adr;
    }




    bool verifierFormatNas(const std::string& chaine) {
    if (chaine.length() != 11) {
        std::cout << chaine.length()  <<  chaine <<  " Gawonou --=======-----" << std::endl;
        return false;
    }

   
    for (size_t i = 0; i < chaine.length(); ++i) {
        if (i == 3 || i == 7) {
            if (chaine[i] != '-') {
                return false;
            }
        }
        else {
            if (!std::isdigit(chaine[i])) {
                std::cout << " Gawonou --=======-----" << std::endl;
                return false;
            }
        }
    }
    return true;
}


    const std::string& getNom() const { return nom; }
    const std::string& getPrenom() const { return prenom; }
    int getAge() const { return age; }
    const Adresse& getAdresse() const { return *adresse; }
    const std::string& getNas() const { return nas; }

};


int main(int argc, const char** argv) {
    try {
        Adresse* addr1  = new Adresse("123 Rue de Paris", "Paris", "France", "AB10");
        Adresse* addr2 =  new Adresse("456 Avenue de Lyon", "Lyon", "France", "AC12");

        Personne p1( "Dupont", "Jean", 30, addr1, "123-456-782", "AC12");
        Personne p2("Martin", "Alice", 25, addr2, "984-654-321","AB10");

        std::cout << p1 << "\n";
    } catch (const std::invalid_argument& e){
        std::cerr << "Exception attrapee" << e.what() << std::endl;
    }catch (const char* e) { // Catch générique pour const char*
    std::cerr << "Exception attrapee: " << e << std::endl;
} 

    return 0;
}