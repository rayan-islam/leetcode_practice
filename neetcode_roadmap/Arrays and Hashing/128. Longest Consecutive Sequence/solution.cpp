#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ans;
        for( int i=0; i<nums.size();i++){
            ans.insert(nums[i]);
        }      
        int longest=0;
        for(int i=0; i<nums.size();i++){
            if(ans.find(nums[i]-1)==ans.end()){
                int l=0;
                while(ans.find(nums[i]+l)!=ans.end()){
                    l++;
                }
                longest=max(longest,l);
            }
        }
        return longest;
    }
};

int main(){

}