class Solution {
public:
    int maximizeGreatness(vector<int>& nums) 
    {
        int n=nums.size();
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            auto it=mp.upper_bound(nums[i]);
            if(it!=mp.end())
            {
                count++;
                mp[it->first]--;
                if(mp[it->first]==0)
                {
                    mp.erase(it->first);
                }
            }
        }
        return count;
    }
};