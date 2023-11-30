#include <iostream>
#include <vector>

using namespace std;

double calcularProbabilidad(int n, double P) {
  
    vector<vector<double>> dp(n + 1, vector<double>(2 * n, 0.0));


    dp[0][0] = 1.0;

 
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 2 * n - 1; ++j) {
            
            double probGanar = (j > 0) ? P * dp[i - 1][j - 1] : 0.0;

      
            double probPerder = (j < 2 * n - 1) ? (1.0 - P) * dp[i - 1][j] : 0.0;

        
            dp[i][j] = probGanar + probPerder;
        }
    }

    double probabilidadTotal = 0.0;
    for (int j = n; j <= 2 * n - 1; ++j) {
        probabilidadTotal += dp[n][j];
    }

    return probabilidadTotal;
}

int main() {
    
    int n = 2;

 
    double P = 0.6;


    double probabilidad = calcularProbabilidad(n, P);

   
    cout << "La probabilidad de que Informáticos CB gane el play-off es: " << probabilidad << endl;

    return 0;
}
