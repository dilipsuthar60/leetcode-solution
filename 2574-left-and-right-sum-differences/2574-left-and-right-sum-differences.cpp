class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums)
    {
        int n=nums.size();
        int right=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            right-=nums[i];
            ans[i]=abs(left-right);
            left+=nums[i];
        }
        return ans;
    }
};