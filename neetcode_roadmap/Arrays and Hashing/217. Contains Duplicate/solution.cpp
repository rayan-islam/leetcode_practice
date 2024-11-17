#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size();i++){
            if (i>0 && nums[i]==nums[i-1]){
                return true;
            }
        }
        return false;
        
    }
};

above complexity o(nlogn)

below complexity o(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> numbers;
        for(auto x:nums){
            if(numbers.find(x)==numbers.end()){
                numbers[x]=1;
            }else{
                numbers[x]++;
            }
        }
        for(auto x:numbers){
            if(x.second>1)
                return true;
        }
        return false;
    }
};
