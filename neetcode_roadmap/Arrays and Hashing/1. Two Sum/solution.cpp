#include<bits/stdc++.h>

using namespace std;

/// best solution 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> numbers;

        for(int i=0; i<nums.size();i++){
            numbers[nums[i]].push_back(i);
        }

        vector<int> ans;
        for(auto x: numbers){
            if(numbers.find(target-x.first)!=numbers.end()){
                if(x.first==target-x.first && numbers[x.first].size()==1){
                    continue;
                }
                ans.push_back(x.second[0]);
                if(numbers[target-x.first].size()>1){
                    ans.push_back(numbers[target-x.first][1]);
                }else{
                    ans.push_back(numbers[target-x.first][0]);
                }
                break;
            }
        }
        return ans;
        
        
    }
};


/////////////////////////////



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for( int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size();j++){
                if(nums[i]+nums[j]==target && i!=j){
                    vector<int> temp{i,j};
                    return temp;
                }
            }

        }   
        vector<int> t;
        return t;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>temp(nums);
        
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums.size()-1;
        vector<int> ans;
        while(left<right){
            if(nums[left]+nums[right]>target){
                right--;
            }else if(nums[left]+nums[right]<target){
                left++;
            }else{
                break;
            }
        }
        
        for(int i=0; i<temp.size();i++){
            if(temp[i]==nums[left]){
                ans.push_back(i);
                break;
            }
        }
        for(int i=0; i<temp.size();i++){
            if(temp[i]==nums[right] && i!=ans[0]){
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};
