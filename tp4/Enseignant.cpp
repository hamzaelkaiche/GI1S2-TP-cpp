/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#include "Enseignant.h"
#include <iostream>

using namespace std;

Enseignant::Enseignant(string nom, string prenom, int age, vector<string> matieres, vector<int> heures)
    :Personne(nom, prenom, age) {
    this->matieres = matieres;
    this->heures = heures;
}

int Enseignant::NombreHeuresTotale() {
    int totale = 0;
    for (int x : heures) {
        totale += x;
    }
    return totale;
}

void Enseignant::Afficher() {
    cout << "{nom: '" << nom << "', prenom: '" << prenom << "', age: " << age << ", heures: {";
    for (int i = 0; i < matieres.size(); i++) {
        if (i != 0) cout << ", ";
        cout << matieres[i] << ": " << heures[i];
    }
    cout << "}}\n";
}

Appreciation Enseignant::CreerAppreciation(std::string nom_etudiant, std::string commentaire) {
    Appreciation appreciation;
    appreciation.nom_enseignant = nom;
    appreciation.nom_etudiant = nom_etudiant;
    appreciation.commentaire = commentaire;
    return appreciation;
}

void Enseignant::AfficherAppreciation(Appreciation appreciation) {
    cout << "{enseignant: '" << appreciation.nom_enseignant << "', etudiant: '" << appreciation.nom_etudiant << "', commentaire: '" << appreciation.commentaire << "'}\n";
}