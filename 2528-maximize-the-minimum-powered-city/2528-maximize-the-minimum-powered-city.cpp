class Solution {
public:
    bool find(vector<int>&nums,int r,int k,long long mid)
    {
        int n=nums.size();
        vector<long long>prefix(n,0);
        for(int i=0;i<n;i++)
        {
            int left=max(0,i-r);
            int right=min(n-1,i+r);
            
            prefix[left]+=nums[i];
            if(right+1<n)
            {
                prefix[right+1]-=nums[i];
            }
        }
        long long sum=0;
        long long count=0;
        for(int i=0;i<n;i++)
        {
            sum+=prefix[i];
            if(sum<mid)
            {
                long long extra=mid-sum;
                if(extra>k)
                {
                    return false;
                }
                k-=extra;
                sum+=extra;
                if((i+2*r+1)<n)
                {
                    prefix[i+2*r+1]-=extra;
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int>&nums, int R, int K) 
    {
        long long ans=0;
        long long l=0;
        long long r=1e18;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(find(nums,R,K,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
