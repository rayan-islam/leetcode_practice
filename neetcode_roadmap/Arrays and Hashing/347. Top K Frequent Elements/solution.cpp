#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ans;
        for(auto x:nums){
            ans[x]=0;
        }
        for(auto x:nums){
            ans[x]+=1;
        }

        //this part is important for this problem
        vector<vector<int>> temp(nums.size()+1);
        for(auto x: ans){
            temp[x.second].push_back(x.first);
        }
        // between the comments

        vector<int> answer;
        for( int i=temp.size()-1; i>=0; i--){
            for( int j=0;j<temp[i].size();j++ ){
                answer.push_back(temp[i][j]);
                if(answer.size()==k){
                    return answer;
                }
            }
        }
        return answer;
    }

    
};

int main(){
    Solution s;

}