class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        if(nums.size()==3){
            return max(nums[0],max(nums[1],nums[2]));
        }
        if(nums.size()==4){
            return max(nums[0]+nums[2],nums[1]+nums[3]);
        }
        vector<int> first_house(nums.size()-1,-1);
        vector<int> last_house(nums.size()-1,-1);
        first_house[0]=nums[0];
        first_house[1]=last_house[0]=nums[1];
        first_house[2]=nums[2]+nums[0];
        last_house[1]=nums[2];
        last_house[2]=nums[3]+nums[1];
        
        for(int i=3; i<first_house.size(); i++){
            first_house[i]=nums[i]+max(first_house[i-2],first_house[i-3]);
            last_house[i]=nums[i+1]+max(last_house[i-2],last_house[i-3]);
        }

        int end=first_house.size()-1;
        return max(max(first_house[end],first_house[end-1]),max(last_house[end],last_house[end-1]));

    }
};
