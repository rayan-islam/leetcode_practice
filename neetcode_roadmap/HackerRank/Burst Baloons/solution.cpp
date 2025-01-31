#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int getMaxScore(int l, int r,vector<int> &balloons, bool considerNeighbours,vector<vector<int>> &dp ){
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    
    int maxScore= INT_MIN;
    
    for( int i=l; i<=r;i++){
        int leftScore=getMaxScore(l,i-1,balloons,true,dp);
        int rightScore=getMaxScore(i+1,r,balloons,true,dp);
        int burstScore=0;
        if(considerNeighbours){
            burstScore=balloons[l-1]*balloons[r+1];
        }else{
            burstScore=balloons[i];
        }
        maxScore=max(maxScore,leftScore+rightScore+burstScore);
    }
    return dp[l][r]=maxScore;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    vector<int> balloons(t);
    
    for(int i=0; i<t; i++){
        cin>> balloons[i];    
    }
    balloons.insert(balloons.begin(),1);
    balloons.push_back(1);
    vector<vector<int>> dp(t+2,vector<int> (t+2,-1));
    
    cout<<getMaxScore(1,t,balloons,false,dp);
    
    return 0;
}

