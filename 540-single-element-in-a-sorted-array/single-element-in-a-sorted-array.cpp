class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if (n==1){
            return nums[0]; 
        }
        int low=0;
        int high=n-1;
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if (mid==0){
                if (nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }
            }
            if (mid==n-1){
                if (nums[mid]!=nums[mid-1]){
                    return nums[mid];
                }
            }
            
            if (nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if ( low!=mid-1 and nums[low]==nums[mid-1]){
                low=mid+1;
            }
            if (high !=mid+1 and nums[high]==nums[mid+1]){
                high=mid-1;
            }
            if ( low != n-1 and nums[low]==nums[low+1]){
                low++;
                if (low !=n-1){
                    low++;
                }
            }
            if ( high != 0 and nums[high]==nums[high-1]){
                high--;
                if (high !=0){
                    high--;
                }
            }
        }
        return nums[mid];
        
    }
};