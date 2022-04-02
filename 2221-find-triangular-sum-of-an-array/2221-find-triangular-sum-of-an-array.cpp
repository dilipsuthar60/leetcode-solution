class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        while(1)
        {
            if(nums.size()==1)
            {
                break;
            }
            vector<int>v;
            int n=nums.size();
            for(int i=0;i<n-1;i++)
            {
                v.push_back((nums[i]+nums[i+1])%10);
            }
            nums=v;
        }
        return nums[0];
    }
};