#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> t;
        set<string> op{"+","-","*","/"};
        for(int i=0; i<tokens.size();i++){
            if(op.find(tokens[i])==op.end()){
                t.push(stoi(tokens[i]));
            }else{
                int op2=t.top();
                t.pop();
                int op1=t.top();
                t.pop();
                if(tokens[i]=="+"){
                    t.push(op1+op2);
                }else if(tokens[i]=="-"){
                    t.push(op1-op2);
                }else if(tokens[i]=="*"){
                    t.push(op1*op2);
                }else if(tokens[i]=="/"){
                    t.push(op1/op2);
                }
            }
        }
        return t.top();
    }
};

int main(){

}