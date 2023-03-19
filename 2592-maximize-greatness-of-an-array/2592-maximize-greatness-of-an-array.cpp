class Solution {
public:
    int maximizeGreatness(vector<int>& nums) 
    {
        int n=nums.size();
        multiset<int>mp;
        for(auto it:nums)
        {
            mp.insert(it);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            auto it=mp.upper_bound(nums[i]);
            if(it!=mp.end())
            {
                count++;
                mp.erase(it);
            }
        }
        return count;
    }
};