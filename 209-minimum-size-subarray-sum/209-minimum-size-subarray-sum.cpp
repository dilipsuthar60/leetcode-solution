class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int c=INT_MAX;
        while(j<nums.size()&&i<n)
        {
                sum+=nums[j];
               while(i<n&&sum>=t)
               {
                   c=min(c,j-i+1);
                   sum-=nums[i];
                   i++;
               }
            j++;

        }
        return c==INT_MAX?0:c;
    }
};