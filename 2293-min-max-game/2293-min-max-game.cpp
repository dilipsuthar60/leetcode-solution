class Solution {
public:
    int minMaxGame(vector<int>& nums) 
    {
        while(true)
        {
             if(nums.size()==1)
            {
                break;
            }
            vector<int>v;
            int f=1;
            for(int i=0;i<nums.size();)
            {
                if(f)
                {
                    v.push_back(min(nums[i],nums[i+1]));
                    i+=2;
                }
                else
                {
                    v.push_back(max(nums[i],nums[i+1]));
                    i+=2;
                }
                f=!f;
            } 
            nums=v;
        }
        return nums[0];
    }
};