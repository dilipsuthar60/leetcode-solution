class Solution {
public:
    // int find(vector<int>&nums,int val)
    // {
    //     int l=0;
    //     int r=nums.size()-1;
    //     int index=0;
    //     while(l<=r)
    //     {
    //         int mid=(l+r)/2;
    //         if(nums[mid]==val)
    //         {
    //             return mid;
    //         }
    //         else if(nums[mid]<val)
    //         {
    //             l=mid+1;
    //         }
    //         else
    //         {
    //             index=mid;
    //             r=mid-1;
    //         }
    //     }
    //     return index;
    // }
    int n;
    int dp[2501][2501];
    int find(vector<int>&nums,int prev,int index)
    {
       set<int>s;
        for(auto &val:nums)
        {
            auto it=s.lower_bound(val);
            if(it!=s.end())
            {
                s.erase(it);
            }
            s.insert(val);
        }
        return s.size();
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        // vector<int>ans;
        // ans.push_back(nums[0]);
        // for(int i=1;i<nums.size();i++)
        // {
        //     if(ans.back()<nums[i])
        //     {
        //         ans.push_back(nums[i]);
        //     }
        //     else
        //     {
        //         int index=find(ans,nums[i]);
        //         ans[index]=nums[i];
        //     }
        // }
        return find(nums,-1,0);
    }
};