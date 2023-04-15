class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ans(n);
        long long max_val=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            max_val=max(max_val,1ll*nums[i]);
            sum+=1ll*nums[i]+max_val;
            ans[i]=sum;
        }
        return ans;
    }
};