class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n)
    {
        nums.push_back(0);
        nums.insert(nums.begin(),0);
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i-1]+nums[i]+nums[i+1]==0)
            {
                n--;
                i++;
            }
        }
        return n<=0;
    }
};