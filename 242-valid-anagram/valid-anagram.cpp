class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>count;
        int n=s.size();
        int n1=t.size();
        if (n!=n1){
            return false;
        }
        int i=0;
        while(i<n){
            count[s[i]]++;
            i++;
        }
        i=0;
        while(i<n){
            count[t[i]]--;
            if (count[t[i]]<0){
                return false;
            }
            i++;
        }
        return true;

    }
};