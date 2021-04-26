/**
 * Author: Hamza EL KAICHE
 * Date: 4-26-2021
 */

#include "Appreciation.h"
#include <iostream>

using namespace std;

void Appreciation::Afficher() {
    cout << "{enseignant: '" << nom_enseignant << "', etudiant: '" << nom_etudiant << "', commentaire: '" << commentaire << "'}\n";
}