class Solution {
public:
    int find(vector<int>&nums)
    {
        vector<int> dp(nums);
        for(int i = 1; i < size(nums); i++) 
            dp[i] = max(nums[i], nums[i] + dp[i-1]);        
        return *max_element(begin(dp), end(dp));
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) 
    {
        unordered_map<char,int>mp;
        for(int i=0,n=chars.size();i<n;i++)
        {
            mp[chars[i]]=vals[i];
        }
        vector<int>nums(s.size(),0);
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                nums[i]=mp[s[i]];
            }
            else
            {
                nums[i]=(s[i]-'a'+1);
            }
        }
        return max(0,find(nums));
    }
};