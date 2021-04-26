/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne {
public:
    Personne();
    Personne(std::string nom, std::string prenom, int age);
    Personne& operator=(const Personne &p);
    
    virtual void Afficher();

protected:
    std::string nom;
    std::string prenom;
    int age;
};

#endif