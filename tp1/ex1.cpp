#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int nb;
    float *elements;
} t_vecteur;

void initialise(int nb, t_vecteur *vec) {
    vec->nb = nb;
    vec->elements = new float[nb]{ 0 };
}

void initialise(int nb, float *tab, t_vecteur *vec) {
    vec->nb = nb;
    vec->elements = new float[nb];

    for (int i = 0; i < nb; i++)
        vec->elements[i] = tab[i];
}

void deteruit(t_vecteur vec) {
    delete[] vec.elements;
}

void somme(t_vecteur vec1, t_vecteur vec2, t_vecteur *res) {
    initialise(max(vec1.nb, vec2.nb), res);
    for (int i = 0; i < vec1.nb; i++)
        res->elements[i] = vec1.elements[i];
    for (int i = 0; i < vec2.nb; i++)
        res->elements[i] += vec2.elements[i];
}

float scalaire(t_vecteur vec1, t_vecteur vec2) {
    float scalaire = 0;
    for (int i = 0; i < min(vec1.nb, vec2.nb); i++)
        scalaire += vec1.elements[i] * vec2.elements[i];
    return scalaire;
}

void lire(t_vecteur vec) {
    for (int i = 0; i < vec.nb; i++)
        cin >> vec.elements[i];
}

void afficher(t_vecteur vec) {
    for (int i = 0; i < vec.nb; i++)
        cout << vec.elements[i] << " ";
    cout << endl;
}

int main() {
    t_vecteur vec1;
    initialise(8, &vec1);

    t_vecteur vec2;
    initialise(5, &vec2);

    lire(vec1);
    lire(vec2);

    t_vecteur s;
    somme(vec1, vec2, &s);

    int p = scalaire(vec1, vec2);

    cout << "somme    = "; afficher(s);
    cout << "scalaire = " << p;

    deteruit(vec1);
    deteruit(vec2);
}