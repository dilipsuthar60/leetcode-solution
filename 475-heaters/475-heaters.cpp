class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>&nums)
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=houses.size();
        auto lowerbound=[&](int val)
        {
            int l=0;
            int r=nums.size()-1;
            int index=0;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(nums[mid]>val)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            if(r<0)
            {
                return 0;
            }
            return nums[r]>val?r:r+1;
        };
        for(int i=0;i<n;i++)
        {
            int index=lowerbound(houses[i]);
            int curr=INT_MAX;
            if(index<nums.size())
            {
                curr=nums[index]-houses[i];
            }
            if(index-1>=0)
            {
                curr=min(curr,houses[i]-nums[index-1]);
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};