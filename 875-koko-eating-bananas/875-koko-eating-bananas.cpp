class Solution {
public:
    int find(vector<int>&v,long long  s,long long h)
    {
        long long sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum=sum+(v[i]+s-1)/s;
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& nums, int h) 
    {
        int ans=0;
        long long l=1;
        long long r=1e9;
        while(l<r)
        {
            long long mid=l+(r-l)/2;
            if(find(nums,mid,h))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};