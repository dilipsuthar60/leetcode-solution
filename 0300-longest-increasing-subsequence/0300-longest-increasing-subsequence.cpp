class Solution {
public:
    int bs(vector<int>&nums,int val)
    {
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]<val)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(!ans.size()||ans.back()<nums[i])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index=bs(ans,nums[i]);
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
};