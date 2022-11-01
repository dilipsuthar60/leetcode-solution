class Solution {
public:
    int dp[4001];
    vector<int>kmp(string s)
    {
        vector<int>lps(s.size(),0);
        int i=1;
        int len=0;
        while(i<s.size())
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len)
                {
                    len=lps[len-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    int find(vector<vector<int>>&nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        int &val=dp[index];
        if(val!=-1)
        {
            return val;
        }
        int ans=1;
        for(int i=1;i<nums[index].size();i++)
        {
            if((i+1)==nums[index][i]*2)
            {
                ans=max(ans,1+find(nums,nums[index][i]+index));
            }
        }
        return val=ans;
    }
    int deleteString(string s) 
    {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>nums(s.size());
        for(int i=0;i<s.size();i++)
        {
            nums[i]=kmp(s.substr(i));
        }
        return find(nums,0);
    }
};