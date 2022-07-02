class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>&nums)
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=houses.size();
        for(int i=0;i<n;i++)
        {
            int index=lower_bound(nums.begin(),nums.end(),houses[i])-nums.begin();
            int curr=INT_MAX;
            if(index<nums.size())
            {
                curr=nums[index]-houses[i];
            }
            if(index-1>=0)
            {
                curr=min(curr,houses[i]-nums[index-1]);
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};