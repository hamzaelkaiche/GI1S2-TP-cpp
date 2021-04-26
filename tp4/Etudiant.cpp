/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#include "Etudiant.h"
#include <iostream>

using namespace std;

Etudiant::Etudiant(string nom, string prenom, int age, vector<string> matieres, vector<float> notes)
    :Personne(nom, prenom, age) {
    this->matieres = matieres;
    this->notes = notes;
}

vector<string> Etudiant::ListeMatieres() {
    return matieres;
}

float Etudiant::Moyenne() {
    float somme = 0;
    for (float note : notes) {
        somme += note;
    }
    return somme / notes.size();
}

void Etudiant::Afficher() {
    cout << "{nom: '" << nom << "', prenom: '" << prenom << "', age: " << age << ", notes: {";
    for (int i = 0; i < matieres.size(); i++) {
        if (i != 0) cout << ", ";
        cout << matieres[i] << ": " << notes[i];
    }
    cout << "}}\n";
}