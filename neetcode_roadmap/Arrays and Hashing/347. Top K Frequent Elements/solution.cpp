#include<bits/stdc++.h>

using namespace std;

///best Solution
class Solution {
public:
    
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ans;
        for(auto x:nums){
            if(ans.find(x)==ans.end())
                ans[x]=0;
            ans[x]+=1;
        }
        vector<pair<int,int>> freq;

        for(auto x:ans){
            freq.push_back(make_pair(x.second,x.first));
        }
        vector<int> answer;
        sort(freq.begin(),freq.end(),cmp);

        for(auto x:freq){
            if(k==0){
                return answer;
            }
            answer.push_back(x.second);
            k--;
        }
        return answer;
    }
  
};
//////////////////////////////////


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
