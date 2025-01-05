#include <iostream>
#include <fstream>
#include <string>

bool replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2) 
{
    // Vérification des chaînes vides
    if (s1.empty() || s2.empty()) 
    {
        std::cerr << "Error: s1 and s2 cannot be empty." << std::endl;
        return false;
    }

    // Ouvrir le fichier source en lecture
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return false;
    }

    // Créer le fichier de sortie
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) 
    {
        std::cerr << "Error: Could not create the output file " << filename << ".replace" << std::endl;
        inputFile.close();
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line)) 
    {
        size_t pos = 0;
        // Remplacer toutes les occurrences de s1 par s2 dans la ligne
        while ((pos = line.find(s1, pos)) != std::string::npos) 
        {
            line.replace(pos, s1.length(), s2);
            pos += s2.length(); // Avancer la position après le remplacement
        }
        outputFile << line << std::endl;
    }

    // Fermer les fichiers
    inputFile.close();
    outputFile.close();
    return true;
}

int main(int argc, char *argv[]) 
{
    // Vérifier le nombre d'arguments
    if (argc != 4) 
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    // Récupérer les arguments
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Appeler la fonction de remplacement
    if (!replaceInFile(filename, s1, s2))
        return 1; // Retourner 1 en cas d'erreur

    std::cout << "Replacement completed! Check " << filename << ".replace" << std::endl;
    return 0;
}
