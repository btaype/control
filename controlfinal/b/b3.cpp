#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Cliente {
    int tiempoEspera;
    double propina;

    Cliente(int tiempo, double tip) : tiempoEspera(tiempo), propina(tip) {}
};


double maximizarGanancias(vector<Cliente>& clientes) {
   
    sort(clientes.begin(), clientes.end(), [](const Cliente& a, const Cliente& b) {
        return (a.propina / a.tiempoEspera) > (b.propina / b.tiempoEspera);
        });

    double ganancias = 0.0;
    double tiempoTotal = 0.0;

   
    for (const Cliente& cliente : clientes) {
        tiempoTotal += cliente.tiempoEspera;
        ganancias += cliente.propina / tiempoTotal;
    }

    return ganancias;
}

int main() {
    
    vector<Cliente> clientes = { {10, 5.0}, {5, 2.0}, {8, 4.0}, {2, 8.0} };

    double gananciasMaximas = maximizarGanancias(clientes);

    cout << "Ganancias máximas del camarero: " << gananciasMaximas << endl;

    return 0;
}


