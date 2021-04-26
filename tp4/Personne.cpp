/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#include "Personne.h"
#include <iostream>

using namespace std;

Personne::Personne() {
    age = 0;
}

Personne::Personne(string nom, string prenom, int age) {
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
}

void Personne::Afficher() {
    cout << "{nom: '" << nom << "', prenom: '" << prenom << "', age: " << age << "}\n";
}

Personne& Personne::operator=(const Personne &p) {
    this->nom = p.nom;
    this->prenom = p.nom;
    this->age = age;
    return *this;
}