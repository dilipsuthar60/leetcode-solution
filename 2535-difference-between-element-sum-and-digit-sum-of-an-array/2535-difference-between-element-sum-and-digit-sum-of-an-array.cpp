class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        int d=0;
        for(int i=0,n=nums.size();i<n;i++)
        {
            sum+=nums[i];
            int val=nums[i];
            while(val)
            {
                d+=val%10;
                val/=10;
            }
        }
        return sum-d;
    }
};