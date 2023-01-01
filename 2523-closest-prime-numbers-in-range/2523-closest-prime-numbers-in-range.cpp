class Solution {
public:
    vector<int> closestPrimes(int left, int right) 
    {
        vector<int>nums;
        int prime[1000005];
        memset(prime,0,sizeof(prime));
        for(int i=0;i<1000005;i++)
        {
            prime[i]=1;
        }
        prime[0]=prime[1]=0;
        for(long long i=2;i*i<1000005;i++)
        {
            if(prime[i]==1)
            {
                for(long long j=i*i;j<1000005;j+=i)
                {
                    prime[j]=0;
                }
            }
        }
        for(int i=left;i<=right;i++)
        {
            if(prime[i])
            {
                nums.push_back(i);
            }
        }
        if(nums.size()<2)
        {
            return {-1,-1};
        }
        vector<vector<int>>now;
        int ans=1e9;
        for(int i=1;i<nums.size();i++)
        {
            ans=min(ans,nums[i]-nums[i-1]);
        }
        for(int i=1;i<nums.size();i++)
        {
            if(ans==(nums[i]-nums[i-1]))
            {
                now.push_back({nums[i-1],nums[i]});
            }
        }
        sort(now.begin(),now.end());
        return now[0];
    }
};