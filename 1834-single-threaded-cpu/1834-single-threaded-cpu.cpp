class Solution {
public:
    vector<int> getOrder(vector<vector<int>>&nums)
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i].push_back(i);
        }
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0;
        long long time=0;
        vector<int>ans;
        while(i<n||pq.size())
        {
            if(!pq.size()&&i<n)
            {
                time=max(time,1ll*nums[i][0]);
            }
            while(i<n&&nums[i][0]<=time)
            {
                pq.push({nums[i][1],nums[i][2]});
                i++;
            }
            auto [burst,index]=pq.top();
            pq.pop();
            ans.push_back(index);
            time+=burst;
        }
        return ans;
    }
};