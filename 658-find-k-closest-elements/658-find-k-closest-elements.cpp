class Solution {
public:
    vector<int> findClosestElements(vector<int>&nums, int k, int x) 
    {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({abs(nums[i]-x),nums[i]});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>ans;
        while(pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};