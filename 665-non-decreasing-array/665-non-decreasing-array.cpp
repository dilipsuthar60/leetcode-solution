class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            auto it=upper_bound(ans.begin(),ans.end(),nums[i]);
            if(it==ans.end())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                *it=nums[i];
            }
        }
        return ans.size()==n||ans.size()==n-1;
    }
};