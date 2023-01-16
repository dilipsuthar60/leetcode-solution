class Solution {
public:
    bool find(vector<int>&nums,int mid,int k)
    {
        int n=nums.size();
        int last=nums[0];
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-last>=mid)
            {
                count++;
                last=nums[i];
            }
        }
        return count>=k;
    }
    int maximumTastiness(vector<int>& price, int k) 
    {
        sort(price.begin(),price.end());
        int l=0;
        int r=1e9;
        int ans=0;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(find(price,mid,k))
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};