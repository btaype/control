#include <iostream>

int encontrarElementoMayoritario(int arr[], int n) {
    int candidato = -1;
    int contador = 0;

    for (int i = 0; i < n; ++i) {
        if (contador == 0) {
            candidato = arr[i];
            contador = 1;
        } else if (arr[i] == candidato) {
            contador++;
        } else {
            contador--;
        }
    }

   
    contador = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == candidato) {
            contador++;
    }
    }

   
    if (contador > n / 2) {
        return candidato;
    } else {
        return -1; 
    }
}

int main() {
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int resultado = encontrarElementoMayoritario(arr, n);

    if (resultado != -1) {
        std::cout << "El elemento mayoritario es: " << resultado << std::endl;
    } else {
        std::cout << "No hay elemento mayoritario en el array." << std::endl;
    }

    return 0;
}
