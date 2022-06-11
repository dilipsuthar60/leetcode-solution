class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int need=sum-x;
        if(need==0)
        {
            return n;
        }
        if(need<0)
        {
            return -1;
        }
        int len=INT_MIN;
        int j=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            while(j<n&&curr>need)
            {
                curr-=nums[j];
                j++;
            }
            if(curr==need)
            {
                len=max(len,i-j+1);
            }
        }
        if(len==INT_MIN)
        {
            return -1;
        }
        return n-len;
    }
};