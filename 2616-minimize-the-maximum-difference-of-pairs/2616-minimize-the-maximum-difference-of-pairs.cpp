class Solution {
public:
    bool find(vector<int>&nums,int p,int mid)
    {
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++)
        {
            if((nums[i]-nums[i-1]<=mid))
            {
                i++;
                count++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p)
    {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.back();
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,p,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};