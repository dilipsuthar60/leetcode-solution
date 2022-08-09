
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>&nums) 
    {
        int ans=0;
        int mod=1e9+7;
        int n=nums.size();
        unordered_map<int,long long>mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=1;
            for(auto &[a,b]:mp)
            {
                if(nums[i]%a==0&&mp.find(nums[i]/a)!=mp.end())
                {
                    long long temp=(1ll*mp[a]*mp[nums[i]/a]);
                    mp[nums[i]]=(mp[nums[i]]+temp)%mod;
                }
            }
            ans=(ans+mp[nums[i]])%mod;
        }
        return ans;
    }
};