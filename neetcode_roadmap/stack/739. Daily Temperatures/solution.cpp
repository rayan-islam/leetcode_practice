#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> temp;
        vector<int> ans(temperatures.size(),0);
        int count=0;
        int flag=1;
        temp.push(make_pair(temperatures[0],0));
        int curr=1;
        while(curr<temperatures.size()){

            pair<int,int> temper=temp.top();
            if(temper.first<temperatures[curr]){
                ans[temper.second]=curr-temper.second;
                temp.pop();
                if(!temp.empty()){
                    continue;
                }else{
                    if(curr+1<=temperatures.size()-1){
                        temp.push(make_pair(temperatures[curr],curr));
                        curr++;
                    }else{
                        break;
                    }
                }
            }else{
                temp.push(make_pair(temperatures[curr],curr));
                curr++;
                
            }
            
            // while(temperatures[i-1]<temperatures[i+count] ){
            //     if(i+count==temperatures.size()-1){
            //         ans[i-1]=0;
            //         flag=0;
            //         break;
            //     }
            //     count++;
            // }
            // if(flag){
            //     ans[i-1]=count;
            // }else{
            //     ans[i-1]=0;
            // }
            // flag=1;
            // count=0;


        }
        return ans;
    }
};

int main(){

}