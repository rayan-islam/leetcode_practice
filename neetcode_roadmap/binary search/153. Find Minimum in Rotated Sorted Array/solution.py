
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left =0
        right=len(nums)-1
        minimum=999999999
        while(left<=right):
            mid=left+(int)(right-left)/2
            if(nums[mid]>=nums[left]):
                minimum=min(minimum,nums[mid])
                left=mid
            else:
                minimum=min(minimum,nums[mid])
                right=mid
        return minimum
