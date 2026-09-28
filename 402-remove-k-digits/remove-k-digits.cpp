class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        string ans;
        int n=num.size();
        int i=0;
        while(i<n and k>0){
            while(!st.empty() and k>0 and num[st.top()]>num[i]){
                st.pop();
                k--;
            }
            st.push(i);
            i++;

        }
        while(i < n) {
            st.push(i);
            i++;
        }
        while(k > 0) {
            st.pop();
            k--;
        }

        while(!st.empty()){
            ans.push_back(num[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        i = 0;
        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if(ans.empty()) {
            return "0";
        }
        return ans;
    }
};