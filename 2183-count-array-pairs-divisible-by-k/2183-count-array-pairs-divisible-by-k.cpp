class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        map<long long,long long>mp;
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int current=__gcd(nums[i],k);
            for(auto &[a,b]:mp)
            {
                if((a*current)%k==0)
                {
                    ans+=b;
                }
            }
            mp[current]++;
        }
        return ans;
    }
};