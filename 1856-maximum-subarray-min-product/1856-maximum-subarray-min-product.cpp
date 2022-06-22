class Solution {
public:
    const int m=1e9+7;
    int maxSumMinProduct(vector<int>& nums) 
    {
        int n=nums.size();
        stack<int>s;
        vector<int>left(n,0),right(n,0);
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&nums[s.top()]>=nums[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                left[i]=-1;
            }
            else
            {
                left[i]=s.top();
            }
            s.push(i);
        }
        while(s.size())
        {
            s.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty()&&nums[s.top()]>=nums[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                right[i]=n;
            }
            else
            {
                right[i]=s.top();
            }
            s.push(i);
        }
        vector<long long>sum(n+1,0);
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+nums[i-1];
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int l=left[i];
            int r=right[i];
            long long x1=(sum[r]-sum[l+1]);
            long long val=nums[i]*x1;
            ans=max(ans,val);
        }
        return ans%m;
    }
};