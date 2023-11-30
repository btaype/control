#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

struct Punto {
    double x, y;
};

bool compararX(const Punto& a, const Punto& b) {
    return a.x < b.x;
}

bool compararY(const Punto& a, const Punto& b) {
    return a.y < b.y;
}

double distancia(const Punto& a, const Punto& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double par_puntos_mas_cercano_en_franja(const std::vector<Punto>& franja, double d_min) {
    int n = franja.size();
    std::sort(franja.begin(), franja.end(), compararY);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < std::min(i + 7, n); ++j) {
            double dist = distancia(franja[i], franja[j]);
            if (dist < d_min) {
                d_min = dist;
            }
        }
    }

    return d_min;
}

double par_puntos_mas_cercano_en_conjunto(std::vector<Punto>& puntos) {
    int n = puntos.size();

  
    if (n <= 3) {
        double d_min = std::numeric_limits<double>::max();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = distancia(puntos[i], puntos[j]);
                d_min = std::min(d_min, dist);
            }
        }
        return d_min;
    }

   
    std::sort(puntos.begin(), puntos.end(), compararX);

    int mitad = n / 2;
    std::vector<Punto> izquierda(puntos.begin(), puntos.begin() + mitad);
    std::vector<Punto> derecha(puntos.begin() + mitad, puntos.end());

  
    double d_izquierda = par_puntos_mas_cercano_en_conjunto(izquierda);
    double d_derecha = par_puntos_mas_cercano_en_conjunto(derecha);

    double d_min = std::min(d_izquierda, d_derecha);

   
    std::vector<Punto> franja;
    for (const auto& punto : puntos) {
        if (std::abs(punto.x - puntos[mitad].x) < d_min) {
            franja.push_back(punto);
        }
    }

    return par_puntos_mas_cercano_en_franja(franja, d_min);
}

int main() {
    std::vector<Punto> conjunto_puntos = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    double resultado = par_puntos_mas_cercano_en_conjunto(conjunto_puntos);
    std::cout << resultado << std::endl;

    return 0;
}
