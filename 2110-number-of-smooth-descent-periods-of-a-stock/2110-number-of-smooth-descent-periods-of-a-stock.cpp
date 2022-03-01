class Solution {
public:
    long long getDescentPeriods(vector<int>& nums)
    {
        int n=nums.size();
        unordered_set<int>mp;
        long long count=0;
        long long len=1;
        for(int i=0;i<n;i++)
        {
            if(i+1<n&&nums[i]==nums[i+1]+1)
            {
                len++;
            }
            else
            {
                len=1;
            }
            count+=len;
        }
        return count;
    }
};