#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Function to convert a string to an integer
// This function takes a string representing a number and converts it to an integer.


int main() {
    int k;
    cin>>k;
    string s;
    cin>>s;
    
    int level=-1;
    int ans=0;
    int n=s.size();
    for(int i=0; i<n;i++){
        
        if(s[i]=='('){
            level++;
        }else if(s[i]==')'){
            level--;
        }else if(level==k){
            string tmp="";
            while(i<n && (s[i]!='(') && (s[i]!=')')){
                tmp+=s[i];
                i++;
            }
            i--;  //so that I don't miss a character
            ans+=stoi(tmp);        
        }
    }
    cout<<ans;
    return 0; // Program ends successfully
}

