#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

//=========================================================================

class String {
    char            *chaine;
    unsigned int    taille;

public:
    String();
    String(const char *);
    String(const String &);
    ~String();
    String &operator=(const String &);
    bool operator==(const String &);
    String &operator+=(const String &);
    String &operator+=(const char *);
    String &operator+=(const char);
    String operator+(const String &);
    char &operator[](unsigned int);
    bool isEmpty();
    void Empty();
    unsigned int getSize();

    friend ostream &operator<<(ostream &os, const String &s);
};

//=========================================================================

String::String() {
    chaine = nullptr;
    taille = 0;
}

String::String(const char *s) {
    taille = strlen(s);
    chaine = new char[taille + 1];
    strcpy(chaine, s);
}

String::String(const String &s) {
    taille = s.taille;
    chaine = new char[taille + 1];
    strcpy(chaine, s.chaine);
}

String::~String() {
    if (taille != 0) {
        delete [] chaine;
    }
}

String &String::operator=(const String &s) {
    taille = s.taille;
    chaine = new char[taille + 1];
    strcpy(chaine, s.chaine);
    return *this;
}

bool String::operator==(const String &s) {
    return !strcmp(chaine, s.chaine);
}

String &String::operator+=(const String &s) {
    if (taille == 0) {
        taille = s.taille;
        chaine = new char[taille + 1];
        strcpy(chaine, s.chaine);
    }
    else {
        taille += s.taille;
        char *nouvelle_chaine = new char[taille + 1];
        strcpy(nouvelle_chaine, chaine);
        strcat(nouvelle_chaine, s.chaine);
        char *tmp = chaine;
        chaine = nouvelle_chaine;
        delete [] tmp;
    }
    return *this;
}

String &String::operator+=(const char *s_chaine) {
    if (taille == 0) {
        taille = strlen(s_chaine);
        chaine = new char[taille + 1];
        strcpy(chaine, s_chaine);
    }
    else {
        taille += strlen(s_chaine);
        char *nouvelle_chaine = new char[taille + 1];
        strcpy(nouvelle_chaine, chaine);
        strcat(nouvelle_chaine, s_chaine);
        char *tmp = chaine;
        chaine = nouvelle_chaine;
        delete [] tmp;
    }
    return *this;
}

String &String::operator+=(const char c) {
    if (taille == 0) {
        taille = 1;
        chaine = new char[2];
        chaine[0] = c;
    }
    else {
        taille++;
        char *nouvelle_chaine = new char[taille + 1];
        strcpy(nouvelle_chaine, chaine);
        nouvelle_chaine[taille - 1] = c;
        char *tmp = chaine;
        chaine = nouvelle_chaine;
        delete [] tmp;
    }
    return *this;
}

String String::operator+(const String &s) {
    String r = *this;
    r += s;
    return r;
}

char &String::operator[](unsigned int i) {
    if (i < 0 || i >= taille) {
        throw out_of_range("indexe invalide");
    }
    return chaine[i];
}

bool String::isEmpty() {
    return taille == 0;
}

void String::Empty() {
    taille = 0;
    delete [] chaine;
    chaine = nullptr;
}

unsigned int String::getSize() {
    return taille;
}

ostream &operator<<(ostream &os, const String &s) {
    os << s.chaine;
    return os;
}

//=========================================================================

int main() {
    String s1 = "hamza";
    s1 += " el kaich";
    s1 += 'e';
    String s2 = "Hello ";
    cout << s2 + s1;
}