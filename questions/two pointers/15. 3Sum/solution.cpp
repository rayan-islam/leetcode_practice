#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int l,r;
        for(int i = 1; i<nums.size();i++){
            //check if duplicate number
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            l=i+1;
            r=nums.size()-1;

            while (l<r){
                if( nums[i]+nums[l]+nums[r]>0){
                    l++;
                }else if(nums[i]+nums[l]+nums[r]<0){
                    r--;
                }else{
                    vector<int> temp{nums[i],nums[l],nums[r]};
                    result.push_back(temp);
                }

            }
            
        }
        return result;

    }
};

int main (){
    vector<int> a{-1,0,1,2,-1,-4};
    // int input;
    // while(cin>>input){
    //     a.push_back(input);
    // }

    Solution ss;


    
}