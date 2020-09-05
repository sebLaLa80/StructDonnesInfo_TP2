#include "score.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>

int main()
{
    
    std::cout << "Debut du programme" << std::endl;

    std::priority_queue<Score> scores;

    std::string partie_string;
    std::string username;
    std::string score_string;
    long partie;

    // Lecture du fichier hiscore.txt à raison de 3 mots par boucles et création des objets Score dans une priority
    // queue

    std::ifstream lecteur("hiscore.txt");
    std::cout << "Ouverture du fichier hiscore.txt" << std::endl;

    while(!lecteur.eof()) {

        try
        {
            lecteur >> partie_string;
            lecteur >> username;
            lecteur >> score_string;
            partie = std::stol(partie_string);
            if (partie == 0) throw 1; 

            if (lecteur.tellg() != -1) {
                Score temp(partie, username, std::stol(score_string));
                scores.push(temp);
                std::cout << "Creation d'une ligne de score" << std::endl;
            }

        }
        catch (const int& code_erreur)
        {
            std::cout << "Erreur! Une ligne n'a pas ete incluse dans le fichier car le numéro de partie est invalide" << std::endl; 
        }

    }

    lecteur.close();
    std::cout << "Fermeture du fichier hiscore.txt" << std::endl;

    //Écriture des objets de types Scores au format demandé dans un fichier asterostorm.txt

    std::ofstream ecriture("asterostorm.txt");
    std::cout << "Ouverture du fichier asterostorm.txt pour l'ecriture des scores" << std::endl;

    while(scores.size() > 0) {
        ecriture << scores.top().getNom() << std::endl;
        ecriture << scores.top().getPartie() << std::endl;
        ecriture << "Asterostorm=" << scores.top().getScore() << std::endl;
        scores.pop();
    }

    ecriture.close();
    std::cout << "Fermeture du fichier asterostorm.txt" << std::endl;
    std::cout << "Fin du programme" << std::endl;

    return 0;
}