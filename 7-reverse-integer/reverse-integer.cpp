class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        int n=x;
        int digit;
        while(n!=0){
            digit=n%10;
            ans=ans*10+digit;
            n=n/10;
        }
         if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }
        return ans;
    }
};