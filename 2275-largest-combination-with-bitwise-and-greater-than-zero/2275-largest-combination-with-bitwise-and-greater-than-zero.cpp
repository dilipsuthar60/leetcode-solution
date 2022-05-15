class Solution {
public:
    int largestCombination(vector<int>& nums)
    {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<32;i++)
        {
            vector<int>v(32,0);
            for(int j=0;j<n;j++)
            {
                if(nums[j]&(1<<i))
                {
                    v[i]++;
                }
            }
            for(int k=0;k<32;k++)
            {
                if(v[k])
                {
                    ans=max(ans,v[k]);
                }
            }
        }
        return ans;
    }
};