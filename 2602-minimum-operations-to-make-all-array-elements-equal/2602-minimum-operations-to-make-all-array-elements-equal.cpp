class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& q) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long long>ans;
        long long total=accumulate(nums.begin(),nums.end(),0ll);
        vector<long long>temp(n+1);
        for(int i=0;i<n;i++)
        {
            temp[i+1]=temp[i]+nums[i];    
        }
        for(int i=0;i<q.size();i++)
        {
            int index=lower_bound(nums.begin(),nums.end(),q[i])-nums.begin();
            long long left_sum=1ll*q[i]*(index)-temp[index];
            long long right_sum=(total-temp[index])-1ll*q[i]*(n-index);
            ans.push_back(left_sum+right_sum);
        }
        return ans;
    }
};