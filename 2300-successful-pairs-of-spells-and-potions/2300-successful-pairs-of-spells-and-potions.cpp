class Solution {
public:
    int find(vector<int>&nums,long long val,long long max_val)
    {
        int l=0;
        int r=nums.size()-1;
        int ans=0;
        int n=nums.size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            if((1ll)*nums[mid]*val>=max_val)
            {
                ans=n-mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& s, vector<int>& nums, long long success) 
    {
        int n=s.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int val=find(nums,s[i],success);
            ans.push_back(val);
        }
        return ans;
    }
};