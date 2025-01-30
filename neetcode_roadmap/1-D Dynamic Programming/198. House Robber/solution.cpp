class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[1],nums[0]);
        }
        if(nums.size()== 3){
            return max(nums[2]+nums[0],nums[1]);
        }
        vector<int> r(nums.size(),-1);
        r[0]=nums[0];
        r[1]=nums[1];
        r[2]=nums[2]+nums[0];
        for(int i=3 ; i<nums.size();i++){
            r[i]=nums[i]+max(r[i-2],r[i-3]);
        }
        
        
        int end =nums.size()-1;
        return max(r[end],r[end-1]);
    }
};
