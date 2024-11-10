
class Solution{
    public:
    int findMin(vector<int> &nums){
        int left =0;
        int right=nums.size()-1;
        int minimum=999999999;
        while(left<=right){
            int mid=left+(int)(right-left)/2;
            if(nums[mid]>=nums[left]){
                if(nums[mid]<minimum){
                    minimum=nums[mid];
                }else{
                    break;
                }
                left=mid;
            }
            else{
                if(nums[mid]<minimum){
                    minimum=nums[mid];
                }else{
                    break;
                }
                right=mid+1;
            }
        }
        return minimum;
            
    }
};
};