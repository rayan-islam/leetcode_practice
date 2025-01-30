#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


const int INF = 1e9; // Large value representing infinity

// Recursive function to solve TSP using DP & Bitmasking
int tsp(int mask, int pos,vector<vector<int>> &dist,vector<vector<int>> &dp) {
    int n=dist.size();   
    if (mask == (1 << n) - 1) // All cities visited
        return dist[pos][0]; // Return to starting city

    if (dp[mask][pos] != -1) // If already computed
        return dp[mask][pos];

    int minCost = INF;
    for (int nxt = 0; nxt < n; nxt++) {
        if (!(mask & (1 << nxt))) { // If city 'nxt' not visited
            int newCost = dist[pos][nxt] + tsp(mask | (1 << nxt), nxt,dist,dp);
            minCost = min(minCost, newCost);
        }
    }
    dp[mask][pos] = minCost;
    return dp[mask][pos];
}

int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        int num_of_city;
        cin>> num_of_city;
        vector<vector<int>> dist(num_of_city, vector<int>(num_of_city));
        vector<vector<int>> dp(1<<num_of_city, vector<int>(num_of_city,-1));
        
        for(int j=0; j<num_of_city; j++){
            for(int k=0; k<num_of_city; k++){
                cin>>dist[j][k];
            }
        }
        
        int minCost = tsp(1, 0,dist,dp); // Start from city 0 with only city 0 visited
        cout << minCost << endl;

    }
    
    
    return 0;
}
