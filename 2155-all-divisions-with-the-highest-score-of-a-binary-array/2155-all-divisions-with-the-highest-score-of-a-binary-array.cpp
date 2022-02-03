class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) 
    {
        int n=nums.size();
        int right=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        map<int,vector<int>,greater<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[left+right].push_back(i);
            if(nums[i]==0)
            {
                left++;
            }
            if(nums[i]==1)
            {
                right--;
            }
        }
         mp[left+right].push_back(n);
        return mp.begin()->second;
    }
};