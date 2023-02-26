class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int count=0;
        for(int j=n-n/2;j<n;j++)
        {
            if(2*nums[i]<=nums[j])
            {
                i++;
            }
        }
        return 2*i;
    }
};