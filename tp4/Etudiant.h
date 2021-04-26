/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Personne.h"
#include <vector>

class Etudiant : public Personne {
public:
    Etudiant(std::string nom, std::string prenom, int age, std::vector<std::string> matieres, std::vector<float> notes);
    
    std::vector<std::string> ListeMatieres();
    float Moyenne();
    void Afficher();

private:
    std::vector<std::string> matieres;
    std::vector<float> notes;
};

#endif