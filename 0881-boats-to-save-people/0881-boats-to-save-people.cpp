class Solution {
public:
    int numRescueBoats(vector<int>& nums, int li) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=n-1;
        int count=0;
        while(l<=r)
        {
            if(nums[l]+nums[r]<=li)
            {
                l++;
                r--;
            }
            else
            {
                r--;
            }
            count++;
        }
        return count;
    }
};