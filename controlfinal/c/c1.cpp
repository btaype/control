#include <iostream>
#include <vector>

using namespace std;


struct Item {
    int peso;
    int valor;
};


void enumerarFormas(int capacidad, const vector<Item>& items, vector<int>& seleccionados, int i, int w) {
    if (i == items.size()) {
        
        if (w == 0) {
            
            for (int j = 0; j < seleccionados.size(); ++j) {
                if (seleccionados[j] == 1) {
                    cout << "Elemento " << j + 1 << " seleccionado." << endl;
                }
            }
            cout << "-------------------------" << endl;
        }
        return;
    }

    
    if (items[i].peso <= w) {
        seleccionados[i] = 1;
        enumerarFormas(capacidad, items, seleccionados, i + 1, w - items[i].peso);
        seleccionados[i] = 0;  
    }

    
    enumerarFormas(capacidad, items, seleccionados, i + 1, w);
}


void todasLasFormas(int capacidad, const vector<Item>& items) {
    vector<int> seleccionados(items.size(), 0);
    enumerarFormas(capacidad, items, seleccionados, 0, capacidad);
}

int main() {
    vector<Item> items = { {2, 10}, {3, 15}, {5, 30}, {7, 25} };
    int capacidad_mochila = 10;

    todasLasFormas(capacidad_mochila, items);

    return 0;
}
