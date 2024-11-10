#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m+n-1;
        int j=m-1;
        int k=n-1;
        if(n==0) return;
        if(m==0){
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }
            return;
        }
        while(i>=0){
            if(j>=0||k>=0){
            if(nums1[j]>=nums2[k] ){
                nums1[i]=nums1[j];
                j--;
            }else{
                nums1[i]=nums2[k];
                k--;
            }
            }
            i--;
        }
        
    }
};




int main() {
    Solution s = Solution();
    vector<int> nums1 = {2,0};
        vector<int> nums2 = {1};
    s.merge(nums1,1,nums2,1);
    
    
    for(int i=0;i<nums1.size();i++){
            std::cout<<nums1[i]<<" "; // Specify the namespace for "cout"
    }   
    return 0;
}
