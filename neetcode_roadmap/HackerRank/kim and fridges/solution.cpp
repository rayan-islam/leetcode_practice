#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9

pair<int,int> home, company;


int getDist(pair<int,int> a,pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int tsp(int mask,int pos , vector<vector<int>> &dist, vector<vector<int>> &dp){
    int n=dist.size()-1;
    
    if(mask==(1<<n)-1){
        return dist[pos][n]; //shob dekha shesh
    }
    
    if(dp[mask][pos]!=-1) return dp[mask][pos]; 
    
    int ans=INF;
    
    for(int next=0; next<n;next++){
        if(!(mask &(1<<next))){  //if not visited
            ans=min(ans,dist[pos][next]+tsp(mask | (1<<next),next,dist,dp));
        }
    }
    dp[mask][pos]=ans;
    return ans;
    
}
int main() {
    for(int i=0; i<10; i++){
        
        int n;
        cin >> n;
        cin >> home.first>> home.second;
        cin >> company.first>> company.second;
        vector<pair<int,int>> fridges(n) ;
    
            
        for(int j=0; j<n;j++){
            cin >> fridges[j].first>> fridges[j].second;
        }
        
        vector<vector<int>> dist(n+1,vector<int> (n+1));
        for(int j=0; j<n; j++){
            dist[n][j]=getDist(home,fridges[j]);
            dist[j][n]=getDist(fridges[j],company);
            for(int k=0; k<n;k++){
                dist[j][k]=getDist(fridges[j],fridges[k]);
            }
        }
        
        int ans=INF;
        
        vector<vector<int>> dp(1<<n,vector<int>(n,-1));
        
        for(int j=0;j<n;j++){
            ans=min(ans,dist[n][j]+tsp(1<<j,j,dist,dp));
        }
        cout<<"# "<<i+1<<" "<<ans<<endl;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
