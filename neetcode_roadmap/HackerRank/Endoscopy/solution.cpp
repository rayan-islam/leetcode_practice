#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int,int>> vp{{0,1},{0,-1},{-1,0},{1,0}};

int n,m;
bool valid(int x,int y){
    return (x>=0 && x<n) && (y>=0 && y<m);
}

bool upor(int i){
    return i==1||i==2||i==4||i==7;
}

bool niche(int i){
    return i==1||i==2||i==5||i==6;
}

bool dane(int i){
    return i==1||i==3||i==4||i==5;
}

bool bame(int i){
    return i==1||i==3||i==6||i==7;
}



int endoscope(int px,int py,int l,vector<vector<int>> &mat, vector<vector<bool>> &visited){
    if(mat[px][py]==0) return 1;
    //cout<<px<<py<<mat[px][py]<<endl;
    if(l==1) return 2;
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{px,py},1});
    int ans=0;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int c=q.front().second;
        
        q.pop();
        if(c>l) continue;
        
        ans++;
        for(int d=0; d<4;d++){
            int dx=x+vp[d].first;
            int dy=y+vp[d].second;
            if(valid(dx,dy) && !visited[dx][dy] && mat[x][y]!=0){
                
                if(d==0 && dane(mat[x][y]) && bame(mat[dx][dy])){
                    visited[dx][dy]=true;
                    q.push({{dx,dy},c+1});
                }else if(d==1 && bame(mat[x][y]) && dane(mat[dx][dy])){
                    visited[dx][dy]=true;
                    q.push({{dx,dy},c+1});
                }else if(d==2 && upor(mat[x][y]) && niche(mat[dx][dy])){
                    visited[dx][dy]=true;
                    q.push({{dx,dy},c+1});
                }else if(d==3 && niche(mat[x][y]) && upor(mat[dx][dy])){
                    visited[dx][dy]=true;
                    q.push({{dx,dy},c+1});
                }
            }
        }
    }
                         
    return ans;
    
}

int main() {
    
    int t;
    cin>>t;
    
    while(t--){
        int posx,posy,l;
        cin >>n>>m>>posx>>posy>>l;
        
        vector<vector<int>> mat(n,vector<int>(m,0));
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        cout<< endoscope(posx,posy,l,mat,visited)-1<<endl;
        
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
