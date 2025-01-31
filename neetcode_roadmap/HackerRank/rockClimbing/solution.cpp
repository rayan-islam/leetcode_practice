#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

bool isValid(int r,int c,vector<vector<int>> &rockMap){
    int n=rockMap.size();
    int m=rockMap[0].size();
    return (r>=0 &&r<n)&& (c>=0 && c<m) &&rockMap[r][c]!=0;
}

int getLevel(vector<vector<int>> &rockMap){
    int n=rockMap.size();
    int m=rockMap[0].size();
    vector<vector<int>> level(n,vector<int> (m,INT_MAX));
    
    priority_queue<pair<int,pair<int,int>>,  vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
    pq.push({0,{n-1,0}});
    level[n-1][0]=0;
    
    vector<int> dc={-1,0,1};
    while(!pq.empty()){
        int currLevel=pq.top().first;
        int r=pq.top().second.first;
        int c=pq.top().second.second;
        pq.pop();
        
        if(rockMap[r][c]==3) return currLevel;
        
        for(int i=0; i<3;i++){
            int nc=c+dc[i];
            if(isValid(r,nc,rockMap)){
                if(level[r][nc]>currLevel){
                    level[r][nc]=currLevel;
                    pq.push({currLevel,{r,nc}});
                }
            }
        }
        
        for(int nr=0; nr<n;nr++){
            
            if(n!= nr && isValid(nr,c,rockMap)){
                if(level[nr][c]>level[r][c]){
                    int newLevel=max(currLevel,abs(nr-r));
                    pq.push({newLevel,{nr,c}});
                    level[nr][c]=newLevel;
                }
            }
        }
    }
    return -1;
    
}


int main() {
    int r,c;
    cin>>r>>c;
    
    vector<vector<int>> rockMap(r,vector<int>(c));
    
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cin>>rockMap[i][j];
        }
    }
    
    cout<<getLevel(rockMap);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
