class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        string ans;
        stack<char>st;
        int i=0;
        while(i<n){
            if (st.empty()){
                if (s[i]!='*'){
                    st.push(s[i]);
                    i++;
                    continue;
                }else{
                    i++;
                    continue;
                }
            }
            if (s[i]=='*'){
                st.pop();
                i++;
                continue;
            }
            st.push(s[i]);
            i++;


        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};