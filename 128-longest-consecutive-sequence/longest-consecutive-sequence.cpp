class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> count;

        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        int ans = 0;

        for(auto it : count){
            int a = it.first;

            if(count.find(a - 1) == count.end()){
                int c = 0;

                while(count.find(a) != count.end()){
                    c++;
                    ans = max(ans, c);
                    a++;
                }
            }
        }

        return ans;
    }
};