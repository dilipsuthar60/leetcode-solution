class Solution {
public:
    vector<int> sumPrefixScores(vector<string>&nums) 
    {
        int n=nums.size();
        unordered_map<unsigned long long,int>mp;
        for(int i=0;i<n;i++)
        {
            unsigned long long hash=0;
            for(auto &ch:nums[i])
            {
                hash=hash*31+(ch);
                mp[hash]++;
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int count=0;
            unsigned long long hash=0;
            for(auto &ch:nums[i])
            {
                hash=hash*31+(ch);
                count+=mp[hash];
            }
            ans[i]=count;
        }
        return ans;
    }
};