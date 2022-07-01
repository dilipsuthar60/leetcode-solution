class Solution {
public:
    int maximumUnits(vector<vector<int>>&nums, int size) 
    {
        int n=nums.size();
        int cost=0;
        sort(nums.begin(),nums.end(),[&](auto a,auto b){return a[1]>b[1];});
        for(int i=0;i<n;i++)
        {
            if(nums[i][0]<=size)
            {
                cost+=nums[i][0]*nums[i][1];
                size-=nums[i][0];
            }
            else
            {
                cost+=min(nums[i][0],size)*nums[i][1];
                break;
            }
        }
        return cost;
    }
};