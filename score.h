#ifndef __SCORE_H__
#define __SCORE_H__

#include <string>

class Score
{
private:
    long partie;
    std::string nom_joueur;
    long score;

public:
    Score(long partie, std::string nom, long score) {
        this->partie = partie;
        nom_joueur = nom;
        this->score = score;
    }

    bool operator<(const Score& score_a_droite) const
    {
        if(this->score < score_a_droite.score)
            return true;
        return false;
    }
    
    long getPartie() const {return this->partie;}
    
    std::string getNom() const {return this->nom_joueur;}
    
    long getScore() const {return this->score;}
};

#endif // __SCORE_H__
