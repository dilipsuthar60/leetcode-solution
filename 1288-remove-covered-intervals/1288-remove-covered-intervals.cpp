class Solution
{
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        
        return v1[0]==v2[0]?v1[1]>v2[1]:v1[0]<v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>&nums)
    {    
        sort(nums.begin(),nums.end(),cmp);
        int n=nums.size();
        int val=nums[0][1];
        int count=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i][1]<=val)
            {
                count++;
            }
             val=max(val,nums[i][1]);
            
        }
        return n-count;
    }
};