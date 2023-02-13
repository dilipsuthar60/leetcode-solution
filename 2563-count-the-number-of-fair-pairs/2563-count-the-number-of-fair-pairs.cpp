class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int r) {
        sort(nums.begin(),nums.end());
        long long count=0;;
        for (int i=0,n=nums.size();i<n;i++)
        {
            long long u=lower_bound(nums.begin()+i+1,nums.end(),l-nums[i])-nums.begin();
            long long v=upper_bound(nums.begin()+i+1,nums.end(),r-nums[i])-nums.begin()-1;
            if (v-u>=0) count+=v-u+1;
        }
        return count;
    }
};