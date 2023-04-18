class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums.front();
        }
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        if(nums.front()<nums.back())
        {
            return nums.front();
        }
        while(l<=r)
        {
            int mid=(l+r)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if(nums[prev]>nums[mid]&&nums[mid]<nums[next])
            {
                return nums[mid];
            }
            if(nums[mid]>=nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;
    }
};