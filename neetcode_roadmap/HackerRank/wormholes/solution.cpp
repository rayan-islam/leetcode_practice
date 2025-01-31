#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int getDist(pair<int,int> a,pair<int,int>b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int dijkstra(vector<vector<int>> &adj, int src,int dest){
    int n=adj.size();
    vector<int> distance(n,INT_MAX);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    distance[src]=0;
    pq.push({0,src});
    
    while(!pq.empty()){
        int currDist=pq.top().first;
        int currNode=pq.top().second;
        pq.pop();
        if(currDist>distance[currNode])
            continue;
        for(int i=0; i<n;i++){
            int weight=adj[currNode][i];
            if(distance[i]>currDist+weight){
                distance[i]=currDist+weight;
                pq.push({distance[i],i});
            }
        }
    }
    return distance[dest];
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int v=2+2*n;
        vector<pair<int,int>> location(v);
        vector<vector<int>> adj(v,vector<int>(v,INT_MAX));
        
        cin>>location[0].first>>location[0].second;
        cin>>location[v-1].first>>location[v-1].second;
        for(int i=1;i<=n;i++){
            cin>>location[i].first>>location[i].second;
            cin>>location[v-1-i].first>>location[v-1-i].second;
            cin>>adj[v-1-i][i];
            adj[i][v-1-i]=adj[v-1-i][i];
        }
        
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                adj[i][j]=min(adj[i][j],getDist(location[i],location[j]));
            }
        }
        cout<<dijkstra(adj,0,v-1)<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
