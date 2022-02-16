class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        long long n=nums.size();
        long long N=n/3;
        vector<long long>prefix(n,1e17),suffix(n,1e17);
        priority_queue<long long>pq_max;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            pq_max.push(nums[i]);
            if(pq_max.size()>N)
            {
                sum-=pq_max.top();
                pq_max.pop();
            }
            if(pq_max.size()==N)
            {
                prefix[i]=sum;
            }
        }
        priority_queue<long long,vector<long long>,greater<long long>>pq_min;
        sum=0;
        for(int i=n-1;~i;i--)
        {
            sum+=nums[i];
            pq_min.push(nums[i]);
            if(pq_min.size()>N)
            {
                sum-=pq_min.top();
                pq_min.pop();
            }
            if(pq_min.size()==N)
            {
                suffix[i]=sum;
            }
        }
        long long ans=1e17;
        for(int i=0;i<n-1;i++)
        {
            if(prefix[i]!=1e17&&suffix[i+1]!=1e17)
            {
                ans=min(ans,prefix[i]-suffix[i+1]);
            }
        }
        return ans;
    }
};