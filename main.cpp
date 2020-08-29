#include "score.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>

int main()
{
    std::priority_queue<Score> scores;

    std::string partie_string;
    std::string username;
    std::string score_string;

    // Lecture du fichier hiscore.txt à raison de 3 mots par boucles et création des objets Score dans une priority
    // queue

    std::ifstream lecteur("hiscore.txt");

    while(!lecteur.eof()) {
        lecteur >> partie_string;
        lecteur >> username;
        lecteur >> score_string;
        if(lecteur.tellg() != -1) {
            Score temp(std::stol(partie_string), username, std::stol(score_string));
            scores.push(temp);
        }
    }

    lecteur.close();

    //Écriture des objets de types Scores au format demandé dans un fichier asterostorm.txt

    std::ofstream ecriture("asterostorm.txt");

    while(scores.size() > 0) {
        ecriture << scores.top().getNom() << std::endl;
        ecriture << scores.top().getPartie() << std::endl;
        ecriture << "Asterostrom=" << scores.top().getScore() << std::endl;
        scores.pop();
    }

    return 0;
}
