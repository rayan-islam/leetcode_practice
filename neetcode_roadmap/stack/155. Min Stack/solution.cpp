#include<bits/stdc++.h>

using namespace std;

class MinStack {
private:
    vector<int> stack;
    int mini;
public:

    MinStack() {
        mini=pow(2,31)-1;
    }
    
    void push(int val) {
        stack.push_back(val);
        mini=min(mini,val);
    }
    
    void pop() {
        int temp=stack[stack.size()-1];
        stack.pop_back();
        if(temp==mini){
            mini=pow(2,31)-1;
            for(int i=0;i<stack.size();i++){
                mini=min(mini,stack[i]);
            }
        }
    }
    
    int top() {
        int temp=stack[stack.size()-1];
        
        return temp;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

}