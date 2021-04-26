/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#ifndef APPRECIATION_H
#define APPRECIATION_H

#include <string>

class Appreciation {
public:
    void Afficher();

private:
    std::string nom_enseignant;
    std::string nom_etudiant;
    std::string commentaire;

    friend class Enseignant;
};

#endif