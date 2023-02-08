class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>&nums) 
    {
        unordered_map<int,int>dp;
        for(auto it:nums)
        {
            int row=it[0];
            int pos=it[1];
            dp[row]|=(1<<(pos-1));
        }
        int ans=2*(n-dp.size());
        for(auto &[row,pos]:dp)
        {
            if(!(pos&(0b0111111110)))
            {
                ans+=2;
            }
            else
            {
                if(!(pos&(0b0111100000))||!(pos&(0b0001111000))||!(pos&(0b0000011110)))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};