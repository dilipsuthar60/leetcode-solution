class Solution {
public:
    vector<int> sumPrefixScores(vector<string>&nums) 
    {
        int n=nums.size();
        unordered_map<long long,int>mp;
        long long mod=1e15+7;
        for(int i=0;i<n;i++)
        {
            long long hash=0;
            for(auto &ch:nums[i])
            {
                hash=(hash*97+(ch))%mod;
                mp[hash]++;
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int count=0;
            long long hash=0;
            for(auto &ch:nums[i])
            {
                hash=(hash*97+(ch))%mod;
                count+=mp[hash];
            }
            ans[i]=count;
        }
        return ans;
    }
};