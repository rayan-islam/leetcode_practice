#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    stack<string> temp;
    set<string> ans;
    vector<string> answer;
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n);

        for(auto x: ans){
            answer.push_back(x);
        }    
        return answer;
    }

    void backtrack(int open,int close,int n){
        if(open==n && close == n){
            ans.insert(getString(n));
            return;
        }
        if(open<n){
            temp.push("(");
            backtrack(open+1,close,n);
            temp.pop();
            
        }

        if(close<open){
            temp.push(")");
            backtrack(open,close+1,n);
            temp.pop();
        }        

    }

    string getString(int n){
        stack<string> temp2;
        string t="";
        for(int i=0; i<2*n;i++){
            temp2.push(temp.top());
            temp.pop();
        }
        for(int i=0; i<2*n;i++){
            t+=temp2.top();
            temp.push(temp2.top());
            temp2.pop();
        }
        return t;
    }
};

int main(){
    int n=4;
    Solution s;
    vector<string> ans=s.generateParenthesis(n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;


}