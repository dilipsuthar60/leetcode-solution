class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int sum=0;
        int n=nums.size();
        int j=0;
        int len=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                len=min(len,i-j+1);
                sum=sum-nums[j];
                j++;
            }
        }
        return len==INT_MAX?0:len;
    }
};