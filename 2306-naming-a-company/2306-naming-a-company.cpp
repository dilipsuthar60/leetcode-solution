class Solution {
public:
    long long distinctNames(vector<string>&nums)
    {
        int dp[26][26];
        memset(dp,0,sizeof(dp));
        unordered_set<string>vis(nums.begin(),nums.end());
        for(auto &it:nums)
        {
            char c=it[0];
            reverse(it.begin(),it.end());
            it.pop_back();
            reverse(it.begin(),it.end());
            for(char ch='a';ch<='z';ch++)
            {
                if(vis.find(ch+it)==vis.end())
                {
                    dp[c-'a'][ch-'a']++;
                }
            }
        }
        long long count=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                count+=(i!=j)?1ll*dp[i][j]*dp[j][i]:0;
            }
        }
        return count;
    }
};