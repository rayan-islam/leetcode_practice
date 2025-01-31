#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int minDist(int n,vector<int> &gates,vector<int> &men){
    int firstGateLast=n-men[0]-men[1]-men[2]+1;
    int secondGateLast=firstGateLast +men[0];
    int thirdGateLast=secondGateLast +men[1];
    
    int ans=INT_MAX;
    for(int i=1; i<=firstGateLast;i++){
        for(int j=i+men[0];j<=secondGateLast;j++){
            for(int k=j+men[1];k<=thirdGateLast;k++){
                int dist=0;
                for(int m=i;m<i+men[0];m++){
                    dist+=abs(gates[0]-m)+1;
                }
                for(int m=j;m<j+men[1];m++){
                    dist+=abs(gates[1]-m)+1;
                }
                for(int m=k;m<k+men[2];m++){
                    dist+=abs(gates[2]-m)+1;
                }
                //cout<<'h'<<endl;
                ans=min(ans,dist);
            }    
        }
    }
    return ans;
}


int main() {
    int n;
    cin>> n;
    vector<int> gates(3);
    vector<int> men(3);
    cin>>gates[0]>>gates[1]>>gates[2];
    cin>>men[0]>>men[1]>>men[2];
    
    cout<<minDist(n,gates,men);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
