// CPP Program to find Eulerian number A(n, m) 
#include <bits/stdc++.h> 
using namespace std; 
  
// Return euleriannumber A(n, m) 
int eulerian(int n, int m) 
{ 
    int dp[n + 1][m + 1]; 
  
    memset(dp, 0, sizeof(dp)); 
  
    // For each row from 1 to n 
    for (int i = 1; i <= n; i++) { 
  
        // For each column from 0 to m 
        for (int j = 0; j <= m; j++) { 
  
            // If i is greater than j 
            if (i > j) { 
  
                // If j is 0, then make that  
                // state as 1. 
                if (j == 0) 
                    dp[i][j] = 1; 
  
                // basic recurrence relation. 
                else
                    dp[i][j] = ((i - j) * 
                     dp[i - 1][j - 1]) +  
                    ((j + 1) * dp[i - 1][j]); 
            } 
        } 
    } 
  
    return dp[n][m]; 
} 
  
// Driven Program 
int main() 
{ 
    int n = 3, m = 1; 
    cout << eulerian(n, m) << endl; 
    return 0; 
} 
