class Solution {
public:
    bool digitCount(string num) 
    {
        int dp[10]={0};
        for(auto &it:num)
        {
            dp[it-'0']++;
        }
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            if((num[i]-'0')!=dp[i])
            {
                return false;
            }
        }
        return true;
    }
    
};