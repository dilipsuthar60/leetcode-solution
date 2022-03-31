class Solution {
public:
    int find(vector<int>nums,int total,int m)
    {
        int sum=0;
        int count=1;
        for(auto it:nums)
        {
            sum+=it;
            if(sum>total)
            {
                sum=it;
                count++;
            }
        }
        return count<=m;
    }
    int splitArray(vector<int>& nums, int m)
    {
        long long sum=0;
        int max1=0;
        for(auto it:nums)
        {
            sum=sum+it;
            max1=max(it,max1);
        }
        if(m==1)
        {
            return (int)sum;
        }
        long long ans=0;
        long long l=max1;
        long long r=sum;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,mid,m))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
