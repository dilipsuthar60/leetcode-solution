class Solution {
public:
    void find(vector<int>&nums,vector<int>&left,vector<int>&right,bool f)
    {
         int n=nums.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(s.size()&&(f?nums[s.top()]>=nums[i]:nums[s.top()]<=nums[i]))
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
            while(s.size()&&(f?nums[s.top()]>nums[i]:nums[s.top()]<nums[i]))
            {
                s.pop();
            }
            if(s.size())
            {
                right[i]=s.top();
            }
            s.push(i);
        }
    }
    long long subArrayRanges(vector<int>& nums) 
    {
        int n=nums.size();
        long long  ans=0;
        vector<int>left_min(n,-1),right_min(n,n),left_max(n,-1),right_max(n,n);
        find(nums,left_min,right_min,1);
        find(nums,left_max,right_max,0);
        for(int i=0;i<n;i++)
        {
            int lmin=i-left_min[i];
            int rmin=right_min[i]-i;
            int lmax=i-left_max[i];
            int rmax=right_max[i]-i;
            ans+=1ll*nums[i]*(lmax*rmax-lmin*rmin);
        }
        return ans;
    }
};