class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        multiset<int>mp(nums.begin(),nums.end());
        int n=nums.size();
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