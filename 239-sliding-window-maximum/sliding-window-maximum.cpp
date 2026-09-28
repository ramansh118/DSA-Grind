class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        deque<int>dp;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while (!dp.empty() and nums[dp.back()]<=nums[i]){
                dp.pop_back();
            }
            dp.push_back(i);
        }
       
        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dp.front()]);
            while(!dp.empty() and dp.front()<=i-k ){
                dp.pop_front();
            }
            while (!dp.empty() and nums[dp.back()]<=nums[i]){
                dp.pop_back();
            }
            dp.push_back(i);
        }
        ans.push_back(nums[dp.front()]);
        return ans;
        
    }
};