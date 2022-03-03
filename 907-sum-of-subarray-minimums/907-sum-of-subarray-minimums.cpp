class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>&nums) 
    {
        int n=nums.size();
        stack<int>s;
        vector<int>left(n,-1),right(n,n);
        for(int i=0;i<n;i++)
        {
            while(s.size()&&nums[s.top()]>=nums[i])
            {
                s.pop();
            }
            if(s.size())
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
            while(s.size()&&nums[s.top()]>nums[i])
            {
                s.pop();
            }
            if(s.size())
            {
                right[i]=s.top();
            }
            s.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int l=i-left[i];
            int r=right[i]-i;
            ans=(ans+1ll*nums[i]*l*r)%mod;
        }
        return (int)ans%mod;
    }
};