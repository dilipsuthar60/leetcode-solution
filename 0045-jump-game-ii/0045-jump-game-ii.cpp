class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        int max_jump=nums[0];
        int jump=nums[0];
        int count=1;
        for(int i=1;i<=min(n-1,max_jump);i++)
        {
            max_jump=max(max_jump,i+nums[i]);
            if(i==n-1)
            {
                return count;
            }
            if(i==jump)
            {
                jump=max_jump;
                count++;
            }
        }
        return 0;
    }
};