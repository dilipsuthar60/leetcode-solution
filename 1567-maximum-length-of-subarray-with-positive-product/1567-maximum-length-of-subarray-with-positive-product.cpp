class Solution {
public:
    int find(vector<int>&nums)
    {
        int len=0;
        int n=nums.size();
        int pos=0;
        int neg=0;
        for(auto &it:nums)
        {
            if(it==0)
            {
                pos=0;
                neg=0;
            }
            else
            {
                if(it<0)
                {
                    neg++;
                }
                else
                {
                    pos++;
                }
            }
            if((neg&1)==0)
            {
                len=max(len,pos+neg);
            }
        }
        return len;
    }
    int getMaxLen(vector<int>& nums) 
    {
        vector<int>nums1=nums;
        reverse(nums1.begin(),nums1.end());
        return max(find(nums),find(nums1));
    }
};