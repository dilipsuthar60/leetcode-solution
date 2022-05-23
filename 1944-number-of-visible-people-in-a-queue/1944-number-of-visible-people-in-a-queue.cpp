class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>&nums)
    {
        stack<int>s;
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()&&s.top()<=nums[i])
            {
                ans[i]++;
                s.pop();
            }
            if(s.size())
            {
                ans[i]++;
            }
            s.push(nums[i]);
        }
        return ans;
    }
};