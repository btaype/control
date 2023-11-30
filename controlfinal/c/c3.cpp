#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> obtenerSecuenciaCrecienteMaxima(const vector<int>& V) {
    int n = V.size();
    vector<int> dp(n, 1);  

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (V[i] > V[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLength = *max_element(dp.begin(), dp.end());

  
    vector<int> resultado;
    for (int i = n - 1; i >= 0; --i) {
        if (dp[i] == maxLength) {
            resultado.push_back(V[i]);
            maxLength--;
        }
    }

    reverse(resultado.begin(), resultado.end());

    return resultado;
}

int main() {
    vector<int> V = { 11, 17, 5, 8, 6, 4, 7, 12, 3 };

    vector<int> secuenciaMaxima = obtenerSecuenciaCrecienteMaxima(V);

    cout << "La secuencia creciente de máxima longitud es: ";
    for (int num : secuenciaMaxima) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
