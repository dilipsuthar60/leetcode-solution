class Solution {
public:
    int mod=1e9+7;
    long long find(vector<int>&nums,long long mid,int n,int k)
    {
        
            long long  count=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]<mid)
                {
                    count+=(mid-nums[i]);
                }
            }
            if(count>k)
            {
                return -1;
            }
            long long pro=1;
            for(int i=0;i<n;i++)
            {
                if(mid<nums[i])
                {
                    pro=(pro*nums[i])%mod;
                }
                else
                {
                    if(count<k)
                    {
                        count++;
                        pro=(pro*(mid+1))%mod;
                    }
                    else
                    {
                        pro=(pro*mid)%mod;
                    }
                }
            }
            return pro;
    }
    int maximumProduct(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int l=0;
        int r=1e7;
        int ans=0;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long val=find(nums,mid,n,k);
            if(val==-1)
            {
                r=mid-1;
            }
            else
            {
                ans=val;
                l=mid+1;
            }
        }
        return (int)ans%mod;
    }
};