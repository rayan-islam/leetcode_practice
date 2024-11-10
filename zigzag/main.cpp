#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    if(numRows==1){
        return s;
    }
        vector<string> a(numRows,"");
    
    int j=0;
    int t=1;
    for(int i=0;i<s.length();i++){
        //cout<<j<<endl;
        a[j]+=s[i];
        if(t==1){
                j++;
                if(j==numRows){
                    j=j-2;
                    t=0;
                }
            }
            else{
                j--;
                if(j==-1){
                    j=j+2;
                    t=1;
                }
            }
        
    }
    int k=0;
    string str="";
    for (int i = 0; i < a.size(); i++)  { 
        str+=a[i];
         
    } 
    return str;
}
    
};

int main(){
    Solution s;
    string str="AB";
    int numRows=1;
    cout<<s.convert(str,numRows);
    return 0;
}