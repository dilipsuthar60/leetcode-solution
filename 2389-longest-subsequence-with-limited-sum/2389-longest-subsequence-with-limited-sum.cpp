class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) 
    {
        sort(nums.begin(),nums.end());
        for(int i=1,n=nums.size();i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        vector<int>ans;
        for(auto it:q)
        {
            int index=upper_bound(nums.begin(),nums.end(),it)-nums.begin();
            ans.push_back(index);
        }
        return ans;
    }
};