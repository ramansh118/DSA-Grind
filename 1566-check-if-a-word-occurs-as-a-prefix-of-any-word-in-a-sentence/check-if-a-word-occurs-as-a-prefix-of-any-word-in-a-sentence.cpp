class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n= sentence.size();
        int n1=searchWord.size();
        int i=0;
        int j=0;
        int c=1;
        while (i<n and j<n1){
            if (sentence[i]== ' ' ){
                i++;
                c++;
                j=0;
            }else if(sentence[i]==searchWord[j]){
                i++;
                j++;
                if (j==n1){
                    int y=i;
                    if (i - n1 == 0 || sentence[i - n1 - 1] == ' ') {
                        return c;
                    }
                    else{
                        j=0;
                        while (i < n && sentence[i] != ' '){
                            i++;
                        }
                        

                    }
                }
            }else{
                j=0;
                i++;
            }
        }
        return -1;
    }
       
    
};