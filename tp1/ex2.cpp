#include <iostream>
#include <cmath>

using namespace std;

class CPoint {
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

private:
    double x, y;
};

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
}