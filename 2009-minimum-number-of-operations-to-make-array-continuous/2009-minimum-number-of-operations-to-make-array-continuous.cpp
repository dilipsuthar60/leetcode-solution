class Solution
{
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int first=nums[i];
            int last=nums[i]+n-1;
            int index=upper_bound(nums.begin(),nums.end(),last)-nums.begin();
            ans=max(ans,index-i);
        }
        return n-ans;
    }
};