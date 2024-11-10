#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        unordered_map<char,char> brackets;
        brackets['[']=']';
        brackets['{']='}';
        brackets['(']=')';
        
        for(auto x:s){
            if(brackets.find(x)==brackets.end()){
                if(!ans.empty()){
                    
                    if(brackets[ans.top()]==x){
                        ans.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                ans.push(x);
            }
        }
        if(!ans.empty()){
            return false;
        }else{
            return true;
        }
    }
};

int main(){

}