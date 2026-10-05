class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>count;
        int n1=nums1.size();
        int n2=nums2.size();
        if (n1>n2){
            for(int i=0;i<n2;i++){
                count[nums2[i]]++;
            }
        }else{
            for(int i=0;i<n1;i++){
                count[nums1[i]]++;
            }
        }
        vector<int>ans;
        if (n1>n2){
            for(int i=0;i<n1;i++){
                if (count[nums1[i]]>0){
                    ans.push_back(nums1[i]);
                    count[nums1[i]] = 0;
                }
            }
        }else{
            for(int i=0;i<n2;i++){
                if (count[nums2[i]]>0){
                    ans.push_back(nums2[i]);
                    count[nums2[i]] = 0;
                }
            }
        }
        return ans;

    }
};