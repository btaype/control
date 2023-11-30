#include <iostream>
#include <vector>
using namespace std;

bool busca_indice_igual_a_valor(const std::vector<int>& arr, int inicio, int fin) {
    if (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (arr[medio] == medio) {
            return true; 
        } else if (arr[medio] > medio) {
           
            return busca_indice_igual_a_valor(arr, inicio, medio - 1);
        } else {
            
            return busca_indice_igual_a_valor(arr, medio + 1, fin);
        }
    }

    return false;  
}

int main() {
    vector<int> arr = {-10, -5, 0, 3, 7, 9, 12, 17};  
    bool resultado = busca_indice_igual_a_valor(arr, 0, arr.size() - 1);

    if (resultado) {
        cout << "Sí existe un índice i tal que X[i] = i." << std::endl;
    } else {
    	cout << "No existe un índice i tal que X[i] = i." << std::endl;
    }

    return 0;
}
