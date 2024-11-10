#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPoint=0;
        for(int i=0; i<t.length(); i++){
            if(s[sPoint]==t[i]){
                sPoint++;
            }
        }
        if(sPoint==s.length()){
            return true;
        }else{
            return false;
        }
    }
};

int main (){
    string s,t;
    cin >> s;
    cin >> t;
    Solution ss;
    if(ss.isSubsequence(s,t)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

}