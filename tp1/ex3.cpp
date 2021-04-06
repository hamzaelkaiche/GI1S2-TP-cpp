#include <iostream>

using namespace std;

//=============================================================================================================

class SetEntiers {
    int nbrelem;
    int *elements;
    int max;

public:
    SetEntiers(int max);
    SetEntiers(int max, int elem);
    SetEntiers(const SetEntiers &s);
    ~SetEntiers();

    void afficher();
    void renverser();
    int cardinal();
    void ajouter(int n);
};

//=============================================================================================================

class SetEntiers_ListeChainee {
    class Element {
    public:
        Element() {
            valeur = 0;
            suivant = nullptr;
        }

        Element(int val) {
            valeur = val;
            suivant = nullptr;
        }

        int valeur;
        Element *suivant;
    };

    int nbrelem;
    Element *premier;
    int max;

public:
    SetEntiers_ListeChainee(int max);
    SetEntiers_ListeChainee(int max, int elem);
    SetEntiers_ListeChainee(const SetEntiers_ListeChainee &s);
    ~SetEntiers_ListeChainee();

    void afficher();
    void renverser();
    int cardinal();
    void ajouter(int n);
};

//=============================================================================================================

int main() {
    SetEntiers_ListeChainee se(10);

    for (int i = 1; i <= 5; i++)
        se.ajouter(i);

    se.afficher();

    cout << "l'ensemble contient " << se.cardinal() << " elements\n";

    se.renverser();
    se.afficher();
}

//=============================================================================================================

SetEntiers::SetEntiers(int max) {
    nbrelem = 0;
    this->max = max;
    elements = new int[max];
}

SetEntiers::SetEntiers(int max, int elem) {
    nbrelem = 1;
    this->max = max;
    elements = new int[max];
    elements[0] = elem;
}

SetEntiers::SetEntiers(const SetEntiers &s) {
    nbrelem = s.nbrelem;
    max = s.max;
    elements = new int[max];
    for (int i = 0; i < max; i++)
        elements[i] = s.elements[i];
}

SetEntiers::~SetEntiers() {
    delete[] elements;
}

void SetEntiers::afficher() {
    cout << "{ ";
    for (int i = 0; i < nbrelem; i++) {
        if (i != 0) cout << ", ";
        cout << elements[i];
    }
    cout << " }\n";
}

int SetEntiers::cardinal() {
    return nbrelem;
}

void SetEntiers::renverser() {
    int i = 0;
    int j = nbrelem - 1;
    while (i < j) {
        int tmp = elements[i];
        elements[i] = elements[j];
        elements[j] = tmp;
        i++;
        j--;
    }
}

void SetEntiers::ajouter(int n) {
    if (nbrelem == max) {
        cout << "le tableau est plein\n";
    }
    else {
        elements[nbrelem++] = n;
    }
}

//=============================================================================================================

SetEntiers_ListeChainee::SetEntiers_ListeChainee(int max) {
    nbrelem = 0;
    this->max = max;
    premier = nullptr;
}

SetEntiers_ListeChainee::SetEntiers_ListeChainee(int max, int elem) {
    nbrelem = 1;
    this->max = max;
    premier = new Element(elem);
}

SetEntiers_ListeChainee::SetEntiers_ListeChainee(const SetEntiers_ListeChainee &s) {
    nbrelem = s.nbrelem;
    max = s.max;
    premier = new Element(s.premier->valeur);
    for (Element *e = s.premier->suivant, *t; e; e = e->suivant, t = t->suivant) {
        t->suivant = new Element(e->valeur);
    }
}

SetEntiers_ListeChainee::~SetEntiers_ListeChainee() {
    Element *e = premier, *tmp;
    while (e) {
        tmp = e;
        e = e->suivant;
        delete tmp;
    }
}

void SetEntiers_ListeChainee::afficher() {
    cout << "{ ";
    for (Element *e = premier; e; e = e->suivant) {
        if (e != premier) cout << ", ";
        cout << e->valeur;
    }
    cout << " }\n";
}

int SetEntiers_ListeChainee::cardinal() {
    return nbrelem;
}

void SetEntiers_ListeChainee::renverser() {
    Element *e = premier,
            *p = nullptr,
            *n;
    while (e != nullptr) {
        n = e->suivant;
        e->suivant = p;
        p = e;
        e = n;
    }
    premier = p;
}

void SetEntiers_ListeChainee::ajouter(int n) {
    if (nbrelem == max) {
        cout << "le tableau est plein\n";
    }
    else {
        if (premier == nullptr) {
            premier = new Element(n);
        }
        else {
            Element *e = premier;
            while (e->suivant) {
                e = e->suivant;
            }
            e->suivant = new Element(n);
        }
        nbrelem++;
    }
}