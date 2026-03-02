#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<long long> linearCongruentialGenerator(long long seed, long long a, long long c, long long m, int numTerms) {
    vector<long long> sequence;
    long long x = seed;
    for (int i = 0; i < numTerms; i++) {
        x = (a * x + c) % m;
        sequence.push_back(x);
    }
    return sequence;
}

int main() {
    int numTerms = 10000000;
    auto start = chrono::high_resolution_clock::now();
    
    linearCongruentialGenerator(12345, 1103515245, 12345, 2147483648, numTerms); 
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Time taken to generate " << numTerms << " numbers: " << duration.count() << " milliseconds" << endl;
    
    return 0;
}
