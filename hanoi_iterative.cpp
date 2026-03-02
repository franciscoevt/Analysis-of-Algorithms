#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

void moveDisk(char source, char destination, int disk) {
}

void hanoiIterative(int n) {
    int totalMoves = pow(2, n) - 1;
    char s = 'A', d = 'C', a = 'B';
    
    if (n % 2 == 0) {
        char temp = d; 
        d = a; 
        a = temp;
    }
    
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) moveDisk(s, d, 1); 
        else if (i % 3 == 2) moveDisk(s, a, 1);
        else if (i % 3 == 0) moveDisk(a, d, 1);
    }
}

int main() {
    int n = 25;
    auto start = chrono::high_resolution_clock::now();
    
    hanoiIterative(n);
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Iterative time for " << n << " disks: " << duration.count() << " milliseconds" << endl;
    
    return 0;
}
