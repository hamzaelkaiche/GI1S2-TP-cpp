#include <iostream>
#include <cmath>

using namespace std;

class CPoint {
    double x, y;

public:
    CPoint() {
        x = y = 0;
    }

    void saisie() {
        cin >> x >> y;
    }

    void afficher() {
        cout << "(" << x << ", " << y << ")\n";
    }

    void translater(double dx, double dy) {
        x += dx;
        y += dy;
    }

    double getAbscisse() {
        return x;
    }

    double getOrdonne() {
        return y;
    }

    double distance(double x, double y) {
        double dx = this->x - x, dy = this->y - y;
        return sqrt(dx * dx + dy * dy);
    }
};

class Triangle {
    CPoint p1, p2, p3;
    static int nb;

public:
    Triangle() {
        nb++;
    }

    int compteur() {
        return nb;
    }

    void saisie() {
        cout << "point 1: "; p1.saisie();
        cout << "point 2: "; p2.saisie();
        cout << "point 3: "; p3.saisie();
    }

    void afficher() {
        cout << "point 1: "; p1.afficher();
        cout << "point 2: "; p2.afficher();
        cout << "point 3: "; p3.afficher();
    }

    void translater(double dx, double dy) {
        p1.translater(dx, dy);
        p2.translater(dx, dy);
        p3.translater(dx, dy);
    }

    double cote1() {
        return p1.distance(p2.getAbscisse(), p2.getOrdonne());
    }

    double cote2() {
        return p2.distance(p3.getAbscisse(), p3.getOrdonne());
    }

    double cote3() {
        return p3.distance(p1.getAbscisse(), p1.getOrdonne());
    }

    bool isocele() {
        double c1 = cote1(),
               c2 = cote2(),
               c3 = cote3();
        return c1 == c2 || c1 == c3 || c2 == c3;
    }

    bool equilateral() {
        double c1 = cote1();
        return c1 == cote2() && c1 == cote3();
    }

    double perimetre() {
        return cote1() + cote2() + cote3();
    }
};

int Triangle::nb = 0;

int main() {
    CPoint p1;
    p1.saisie();
    p1.translater(0, 0);
    cout << "p1 = "; p1.afficher();

    CPoint p2;
    p2.saisie();
    p2.translater(1, 1);
    cout << "p2 = "; p2.afficher();

    cout << "distance(p1, p2) = " << p1.distance(p2.getAbscisse(), p2.getOrdonne()) << endl;

    Triangle t1, t2, t3;
    cout << "nombre de triangle = " << t1.compteur() << endl;
}