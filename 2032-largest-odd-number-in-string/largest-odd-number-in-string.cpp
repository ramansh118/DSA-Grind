class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int c=-1;
        for(int i=n-1;i>=0;i--){
            if (num[i]%2==1){
               c=i;
               break; 
            }
        }
        if (c==-1){
            return "";
        }
        return num.substr(0,c+1);
        
    }
};