#include <iostream>
#include <string>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <shlobj.h>



namespace fs = std::filesystem;


void afficherDateCreation(const fs::path& chemin){

    try
    {
        auto ftime = fs::last_write_time(chemin);
        auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
            ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
        );

        std::time_t tt = std::chrono::system_clock::to_time_t(sctp);
        std::cout << std::put_time(std::localtime(&tt), "%d-%m-%Y %H:%M");

    }
    catch (const std::exception& e) {
         std::cerr << "Erreur : lors de la lecture de la date de creation " << e.what() << std::endl;
        }
}

bool rechercherFichier( const fs::path& dossier, const std:: string& extension){
    bool trouve = false;

    try
    {
        if (!fs::exists(dossier) || !fs::is_directory(dossier)){
         std::cerr << "Erreur : le dossier " << dossier.string() << "n' existe pas  ou n'est pas un repertoire" << std::endl;
        return false;
    
    }


    for(const auto& entry : fs::recursive_directory_iterator(dossier, fs::directory_options::skip_permission_denied)){

        try
        {
            if(!entry.is_directory()){
                std::string ext = entry.path().extension().string();


                if(extension.empty()  || ext == extension ){
                    trouve = true;


                    std::cout << "\n Ficher trouver : " << entry.path().string() << std::endl;
                    std::cout << "La Taile : " << fs::file_size(entry.path()) / 1024.0 << "Ko" <<  std::endl;
                    std::cout << "\t --> Cree le : ";  afficherDateCreation(entry.path());
                    std::cout << std::endl;


                    // Dossier parent

                    fs::path parent = entry.path().parent_path();
                    std::cout << "\n Dossier parent :" << parent.string() << std::endl;
                    std::cout << "\t --> Cree le  "; afficherDateCreation(parent);
                    std::cout << std::endl;

                }
            }
        }
        catch (const fs::filesystem_error& e){
            std::cerr << "Erreur lors de la lecteur du fichiers : " << e.what() << std::endl;
        }

    }

    }
    catch (const fs::filesystem_error& e)
        {
            std::cerr << "Erreur lors de l access du fichiers : " << e.what() << std::endl;
        }

        return trouve;
}


int main(int argc, const char** argv) {

    char cheminBureau[MAX_PATH];
    std::string extension;

    if(SHGetFolderPath(NULL, CSIDL_DESKTOP, NULL, 0, cheminBureau) != S_OK)
    {
            std::cerr << "Erreur lors de recuperation des fichiers bureau : " << std::endl;
            return 1;
    }


    std::cout << "Chemin du Bureau : " << cheminBureau << std::endl;

    // Saisir l'extension du fichier à rechercher
    std::cout << "Extension du fichier arechercher (ex: .txt, .png) [laisser vide pour tout] : ";
    std::getline(std::cin, extension);



    std::cout << "\n Recherche dans : " << cheminBureau << "\n" << std::endl;

    bool trouve = rechercherFichier(cheminBureau, extension);

    if (trouve) {
        std::cout << "\n Des fichiers avec l'extension '" << extension << "' ont ete trouves !" << std::endl;
    } else {
        std::cout << "\n Aucun fichier avec l'extension '" << extension << "' n'a ete trouve." << std::endl;
    }

    return 0;
}

