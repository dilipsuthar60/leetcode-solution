class Solution {
public:
    int N=1e5+10;
    void update(int i,int val,vector<int>&bit)
    {
        while(i<N)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int find(int i,vector<int>&bit)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    int find_(int i,vector<int>&bit)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        vector<int>bitl(N),bitr(N);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums1[i]]=i+1;
        }
        vector<int>nums(n,0);
        for(int i=0;i<n;i++)
        {
            nums[i]=mp[nums2[i]];
        }
        for(int i=0;i<n;i++)
        {
            update(nums[i],1,bitr);
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            update(nums[i],-1,bitr);
            int left=find(nums[i]-1,bitl);
            int right=find_(N-1,bitr)-find_(nums[i],bitr);
            ans+=(1ll*left*right);
            update(nums[i],1,bitl);
        }
        return ans;
    }
};