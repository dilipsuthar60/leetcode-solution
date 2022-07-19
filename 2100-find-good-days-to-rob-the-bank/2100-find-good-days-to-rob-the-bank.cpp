class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int t)
    {
        int n=nums.size();
        vector<int>left(n,0),right(n,0);
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                left[i]=left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
            {
                right[i]=right[i+1]+1;
            }
        }
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(left[i]>=t&&right[i]>=t)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};