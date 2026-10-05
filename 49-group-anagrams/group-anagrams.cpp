class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>count;
        vector<string>s;
        int n=strs.size();
        for (int i=0;i<n;i++){
            string ans=strs[i];
            sort(ans.begin(),ans.end());
            s.push_back(ans);
        }
        for(int i=0;i<n;i++){
            count[s[i]].push_back(strs[i]);
        }
        vector<vector<string>> ans;

        for(auto it:count){
            ans.push_back(it.second);
        }

        return ans;
    }
};