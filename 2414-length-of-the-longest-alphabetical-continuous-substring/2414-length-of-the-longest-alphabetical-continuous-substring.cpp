class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
         int cus = 1;
        int maxs = 1;
        
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                if(s[i] == s[i-1]+1){
                    cus+=1;
            }
            else{
                maxs = max(maxs,cus);
                cus = 1;
            }
        }
       }
        return max(maxs,cus);
    }
};