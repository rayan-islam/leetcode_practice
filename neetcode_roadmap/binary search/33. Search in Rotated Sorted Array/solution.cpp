#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right= nums.size()-1;
        int mid;
        int mini=99999999;
        int mini_index;

        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]>=nums[left]){
                if(nums[left]<mini){
                    mini=nums[left];
                    mini_index=left;
                }
                left=mid+1;
            }else{
                if(nums[mid]<mini){
                    mini=nums[mid];
                    mini_index=mid;
                }
                right=mid;

            }

        }
        cout<<mini_index;
        if(nums[mini_index]==target){
            return mini_index;
        }else if(nums[nums.size()-1]>=target){
            left=mini_index+1;
            right=nums.size()-1;
        }else{
            left=0;
            right=mini_index-1;
        }

        
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

        return -1;
    }
};


int main(){
    vector<int> q={5,1,3};
    Solution s;
    cout<<s.search(q,0);

}