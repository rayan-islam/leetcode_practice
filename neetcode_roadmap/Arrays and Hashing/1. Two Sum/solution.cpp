#include<bits/stdc++.h>

using namespace std;

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


int main(){

}