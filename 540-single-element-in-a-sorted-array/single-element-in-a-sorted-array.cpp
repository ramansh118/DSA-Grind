class Solution {
     int binarysearch(vector<int>& nums,int low,int high){
        int n=nums.size();
        int mid=(low+high)/2;
        if (low > high) {
            return -1;
        }
        if (mid==0){
            if (nums[mid]!=nums[mid+1]){
                return nums[mid];
            }else{
                return -1;
            }
        }
        if (mid==n-1){
            if (nums[mid]!=nums[mid-1]){
                return nums[mid];
            }else{
                return -1;
            }
        }
        if (nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]){
            return nums[mid];
        }
        int right =binarysearch(nums,low,mid-1);
        if (right != -1){
            return right;
        }
        return binarysearch(nums,mid+1,high);
        
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if (n==1){
            return nums[0]; 
        }
        int low=0;
        int high=n-1;
        int ans=binarysearch(nums,low,high);
        return ans;
        
    }
};