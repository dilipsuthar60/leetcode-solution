class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& nums) 
    {
        int n=s.size();
        vector<int>dp[26];
        for(int i=0;i<n;i++)
        {
            dp[s[i]-'a'].push_back(i);
        }
        int count=0;
        for(auto val:nums)
        {
            int x=-1;
            int yes=1;
            for(auto t:val)
            {
                auto it=upper_bound(dp[t-'a'].begin(),dp[t-'a'].end(),x);
                if(it==dp[t-'a'].end())
                {
                    yes=0;
                    break;
                }
                else
                {
                    x=*it;
                }
            }
            count+=yes;
        }
        return count;
    }
};