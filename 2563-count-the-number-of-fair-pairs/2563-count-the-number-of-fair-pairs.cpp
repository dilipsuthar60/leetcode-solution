class Solution {
public:
    long long find(vector<int>&nums,int value)
    {
        int n=nums.size();
        int l=0;
        int r=n-1;
        long long count=0;
        while(l<r)
        {
            int sum=nums[l]+nums[r];
            if(sum<=value)
            {
                count+=(r-l);
                l++;
            }
            else
            {
                r--;
            }
        }
        return count;
    }
    long long countFairPairs(vector<int>& nums, int l, int r) 
    {
        sort(nums.begin(),nums.end());
        return find(nums,r)-find(nums,l-1);
    }
};