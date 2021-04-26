/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#include "Personne.h"
#include "Etudiant.h"
#include "Enseignant.h"
#include "Appreciation.h"

void Affichage(Personne & p) {
    p.Afficher();
}

int main() {
// A
    Personne personnes[3] = {
        {"nomA", "prenomA", 21},
        {"nomB", "prenomB", 22},
        {"nomC", "prenomC", 23}
    };
    
    for (int i = 0; i < 3; i++) {
        personnes[i].Afficher();
    }
    
// B
    Etudiant etudiant("nomEtudiant", "prenomEtudiant", 21, {"c++", "math"}, {20, 20});
    Affichage(etudiant);
    
    Enseignant enseignant("nomEnseignant", "prenomEnseignant", 21, {"c++", "math", "anglais"}, {7, 7, 3});
    Affichage(enseignant);

// C
    Appreciation appreciation = enseignant.CreerAppreciation("nomEtudiant", "un commentaire");
    enseignant.AfficherAppreciation(appreciation);
}