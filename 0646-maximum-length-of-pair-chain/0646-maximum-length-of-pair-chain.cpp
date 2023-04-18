class Solution {
public:
    int findLongestChain(vector<vector<int>>&nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a[1]<b[1];});
        int count=1;
        vector<int>v=nums[0];
        for(int i=1;i<n;i++)
        {
            if(v[1]<nums[i][0])
            {
                count++;
                v=nums[i];
            }
        }
        return count;
    }
};