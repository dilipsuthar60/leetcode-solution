class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n=s.size();
        vector<int>dp(26,-1);
        for(int i=0;i<n;i++)
        {
            dp[s[i]-97]=i;
        }
        vector<int>ans;
        int last=0;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,dp[s[i]-97]);
            if(mx==i)
            {
                ans.push_back(i-last+1);
                last=i+1;
            }
        }
        return ans;
    }
};