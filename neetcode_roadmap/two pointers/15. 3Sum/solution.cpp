#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
        vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        set<vector<int>> temp;
        sort(nums.begin(),nums.end());


        for(int i=0; i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]>0){
                    //cout<<"int left /n";
                    r--;
                }else if(nums[i]+nums[l]+nums[r]<0){
                    //cout<<"in right /n";
                    l++;
                }else{
                    //cout<< "in answer/n";
                    temp.insert({nums[i],nums[l],nums[r]});
                    //cout<<"in here";
                    l++;
                    r--;
                }
            }
        }

        for(auto x:temp){
            answer.push_back(x);
        }
        return answer;
    }
};

int main(){
    vector<int> nums{-2,0,0,2,2};
    vector<vector<int>> answer;

    Solution s;
    answer=s.threeSum(nums);
    for(auto x:answer){
        for(auto y: x){
            cout << y<<" ";
        }
        cout<<endl;
    }

}