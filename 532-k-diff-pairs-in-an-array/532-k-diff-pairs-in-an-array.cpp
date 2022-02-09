class Solution {
public:
    bool find(vector<int>&nums,int l,int r,int val)
    {
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==val)
            {
                return true;
            }
            if(nums[mid]<val)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return false;
    }
    int findPairs(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        unordered_set<int>s;
        for(int i=0;i<n-1;i++)
        {
            if(find(nums,i+1,n-1,nums[i]+k))
            {
                s.insert(nums[i]);
            }
        }
        return s.size();
    }
};