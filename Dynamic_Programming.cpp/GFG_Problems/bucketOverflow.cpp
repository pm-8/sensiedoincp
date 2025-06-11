// C++ program to find amount
// of water in a given glass Using Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

double waterOverflow(int k, int r, int c) {
    
    // DP matrix to simulate water flow in glasses
    vector<vector<double>> memo(r, vector<double>(r, 0.0));
    
    // Initial water in top glass
    memo[0][0] = k;
    
    // Simulate water flow through triangle
    for (int row = 0; row < r - 1; row++) {
        for (int col = 0; col <= row; col++) {
            
            // Calculate water overflow
            double excess = max(0.0, memo[row][col] - 1.0);
            
            // Distribute excess water
            if (excess > 0) {
                
                // Cap current glass
                memo[row][col] = 1.0;
                
                // Flow to bottom glasses
                memo[row + 1][col] += excess / 2.0;
                memo[row + 1][col + 1] += excess / 2.0;
            }
        }
    }
    
    // Return water in target glass
    return min(1.0, memo[r - 1][c - 1]);
}

int main() {
    int k = 3;
    int r = 2;
    int c = 1;
    
    double waterAmount = waterOverflow(k, r, c);
    cout << waterAmount << endl;
    
    return 0;
}