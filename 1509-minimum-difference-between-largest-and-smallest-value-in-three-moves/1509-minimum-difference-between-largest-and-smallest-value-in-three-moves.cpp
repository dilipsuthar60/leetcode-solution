class Solution {
public:
    int minDifference(vector<int>& nums) 
    {
        int ans=INT_MAX;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=max(0,n-4);
        while(i<n&&j<n)
        {
            ans=min(ans,nums[j++]-nums[i++]);
        }
        return ans;
    }
};