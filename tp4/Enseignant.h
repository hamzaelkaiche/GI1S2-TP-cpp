/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "Personne.h"
#include "Appreciation.h"
#include <vector>

class Enseignant : public Personne {
public:
    Enseignant(std::string nom, std::string prenom, int age, std::vector<std::string> matieres, std::vector<int> heures);
    
    int NombreHeuresTotale();
    void Afficher();
    Appreciation CreerAppreciation(std::string nom_etudiant, std::string commentaire);

private:
    std::vector<std::string> matieres;
    std::vector<int> heures;
};

#endif