#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> currPath;
vector<int> cyclePath;
int minSum=INT_MAX;

int nodeSum(vector<int> &path){
    int sum=0;
    for(int i:path){
        sum+=i;
    }
    return sum;
}

void findCycle(vector<vector<int>> &adj,int pos,vector<bool> &visited,vector<int>&currPath){
    visited[pos]=true;
    currPath.push_back(pos);
    
    for(int i:adj[pos]){
        if(!visited[i]){
            
            findCycle(adj,i,visited,currPath);
        }else{
            if(currPath[0]!=i) continue;
            else{
                if(nodeSum(currPath)<minSum){
                    minSum=nodeSum(currPath);
                    cyclePath=currPath;
                }
            }
        }
    }
    visited[pos]=false;
    currPath.pop_back();
}

int main() {
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,false);
    
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            int r,c;
            cin>>r>>c;
            adj[r].push_back(c);
        }
    }
    
    for(int i=1; i<n;i++){
        findCycle(adj,i,visited, currPath);
    }
    
    sort(cyclePath.begin(),cyclePath.end());
    for(int i:cyclePath){
        cout<<i<<" ";
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
