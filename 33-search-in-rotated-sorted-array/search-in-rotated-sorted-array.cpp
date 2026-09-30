class Solution {
    
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if (nums.size()==1){
            if (nums[0]==target){
                return 0;
            }else{
                return -1;
            }
        }
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;

            if (nums[mid]==target){
                return mid;
            }
            if (mid==0){
                if (nums[1]==target){
                    return 1;
                }else{
                    return -1;
                }
            }
            if (mid==n-1){
                if (nums[n-2]==target){
                    return n-2;
                }else{
                    return -1;
                }
            }
            if ((nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]) || (nums[mid]<nums[mid+1] and nums[mid]<nums[mid-1])){
                if (nums[low]<=target and nums[mid-1]>=target){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if (nums[low]==target){
                    return low;
                }
                if (nums[high]==target){
                    return high;
                }
                if (nums[low]>nums[mid-1]){
                    if (nums[mid+1]<=target and nums[high]>=target){
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }else{
                    if (nums[low]<=target and nums[mid-1]>=target){
                        high=mid-1;
                    }else{
                        low=mid+1;
                    }
                }
            }
        }
        return -1;
    }
};