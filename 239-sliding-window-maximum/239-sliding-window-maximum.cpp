class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n=nums.size();
        deque<int>dq;
        for(int i=0;i<k;i++)
        {
            while(dq.size()&&nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int>ans;
        ans.push_back(nums[dq.front()]);
        for(int i=k;i<n;i++)
        {
            if(i-k==dq.front())
            {
                dq.pop_front();
            }
            while(dq.size()&&nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};