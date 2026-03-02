#include <iostream>
#include <chrono>

using namespace std;

void hanoiRecursive(int n, char source, char destination, char auxiliary) {
    if (n == 0) return;
    hanoiRecursive(n - 1, source, auxiliary, destination);
    hanoiRecursive(n - 1, auxiliary, destination, source);
}

int main() {
    int n = 25;
    auto start = chrono::high_resolution_clock::now();
    
    hanoiRecursive(n, 'A', 'C', 'B');
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Time taken for " << n << " disks: " << duration.count() << " milliseconds" << endl;
    
    return 0;
}
