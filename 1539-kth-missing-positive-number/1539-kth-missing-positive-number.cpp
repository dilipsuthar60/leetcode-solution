class Solution {
public:
    int findKthPositive(vector<int>&nums, int k) 
    {
        int l,r;
        l=0;
        r=(int)nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]-mid-1<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l+k;
    }
};