class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=n-1;i>1;i--)
        {
            int l=0;
            int r=i-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>nums[i])
                {
                    count+=(r-l);
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return count;
    }
};