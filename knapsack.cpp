#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Usamos __attribute__((optimize("O0"))) para que el compilador NO optimice esta función
__attribute__((optimize("O0")))
int knapsack_exhaustive(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    if (n == 0 || capacity == 0) return 0;
    
    if (weights[n-1] > capacity) {
        return knapsack_exhaustive(capacity, weights, values, n-1);
    } else {
        int include = values[n-1] + knapsack_exhaustive(capacity - weights[n-1], weights, values, n-1);
        int exclude = knapsack_exhaustive(capacity, weights, values, n-1);
        return (include > exclude) ? include : exclude;
    }
}

int main() {
    cout << left << setw(10) << "n" << setw(25) << "Tiempo (segundos)" << "Resultado Maximo\n";
    cout << string(55, '-') << "\n";

    int n = 4;
    double time_limit = 600.0;
    
    random_device rd;
    mt19937 gen(rd());

    while (true) {
        // Aumentamos la capacidad para que el algoritmo no termine rápido por falta de espacio
        int capacity = 1000; 
        vector<int> weights(n);
        vector<int> values(n);

        uniform_int_distribution<> weight_dist(1, 10);
        uniform_int_distribution<> value_dist(1, 100);

        for (int i = 0; i < n; ++i) {
            weights[i] = weight_dist(gen);
            values[i] = value_dist(gen);
        }

        auto start_time = high_resolution_clock::now();
        int max_value = knapsack_exhaustive(capacity, weights, values, n);
        auto end_time = high_resolution_clock::now();

        duration<double> execution_time = end_time - start_time;

        cout << left << setw(10) << n << setw(25) << fixed << setprecision(6) << execution_time.count() << max_value << "\n";

        if (execution_time.count() > time_limit) {
            cout << string(55, '-') << "\n";
            cout << "Limite de 10 minutos alcanzado. n final: " << n << "\n";
            break;
        }
        n++;
    }
    return 0;
}
