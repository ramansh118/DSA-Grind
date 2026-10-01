class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if (nums.size()==1){
            return nums[0];
        }
        int mid=0;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            mid=(low+high)/2;
            if (mid==0){
                if(nums[0]>nums[1]){
                    return nums[1];
                }else{
                    return nums[0];
                }
            }
            if (mid==n-1){
                if (nums[n-1]>nums[n-2]){
                    return nums[n-2];
                }else{
                    return nums[n-1];
                }
            }
            if (nums[mid]<nums[mid+1] and nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            if (nums[mid]>nums[mid-1] and nums[mid]<nums[mid+1]){
                if (nums[mid-1]<nums[mid+1] and nums[mid-1]<nums[high]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if (nums[low]>nums[mid+1]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }

        }
        return mid;
    }
};