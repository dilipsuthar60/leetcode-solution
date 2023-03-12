class Solution {
public:
    int maxScore(vector<int>&nums) 
    {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        int count=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            count+=(sum>0);
        }
        return count;
    }
};