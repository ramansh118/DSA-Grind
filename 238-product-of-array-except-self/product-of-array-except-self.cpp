class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        int low=0;
        int high=n-1;
        int prefix=1;
        int sufix=1;
        while(low<n){
            ans[low]=ans[low]*prefix;
            prefix=prefix*nums[low];
            low++;
        }
        while(high>=0){
            ans[high]=ans[high]*sufix;
            sufix=sufix*nums[high];
            high--;
        }
        return ans;
    }
};