class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n and k;i++)
        {
            long long prev=(i==0)?0:nums[i-1];
            long long missing=min(k+0ll,max(0ll,0ll+nums[i]-prev-1));
            k-=missing;
            sum+=(prev+1+prev+missing)*(missing)/2;
        }
        if(k)
        {
            sum+=(nums.back()+1+nums.back()+k+0ll)*k/2;
        }
        return sum;
    }
};