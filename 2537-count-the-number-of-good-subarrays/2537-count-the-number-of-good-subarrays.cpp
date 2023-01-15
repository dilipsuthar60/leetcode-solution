class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n=nums.size();
        long long count=0;
        int j=0;
        unordered_map<long long,long long>mp;
        long long len=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            count+=(mp[nums[i]]-1);
            while(count>=k)
            {
                count-=(mp[nums[j]]-1);
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                {
                    mp.erase(nums[j]);
                }
                j++;
            }
            len+=(i-j+1);
        }
        return (1ll*n*(n+1)/2)-len;
    }
};