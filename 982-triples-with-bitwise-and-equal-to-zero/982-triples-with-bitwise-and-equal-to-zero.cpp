class Solution {
public:
    int countTriplets(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[1<<16]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[nums[i]&nums[j]]++;
            }
        }
        int count=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<(1<<16);i++)
            {
                if((i&nums[k])==0)
                {
                    count+=dp[i];
                }
            }
        }
        return count;
    }
};