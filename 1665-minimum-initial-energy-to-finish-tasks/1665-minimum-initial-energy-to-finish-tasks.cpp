class Solution {
public:
    bool find(vector<vector<int>>&nums,long long mid)
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i][1]<=mid)
            {
                mid-=nums[i][0];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>&nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i].push_back(nums[i][1]-nums[i][0]);
        }
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a[2]>b[2];});
        long long l=0;
        long long r=0;
        for(int i=0;i<n;i++)
        {
            r+=nums[i][1];
        }
        int ans=0;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(find(nums,mid))
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