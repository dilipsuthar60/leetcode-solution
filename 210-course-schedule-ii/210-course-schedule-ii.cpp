class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& nums) 
    {
        vector<int>ind(num,0);
        vector<int>dp[num];
        for(auto &it:nums)
        {
            dp[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<num;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto &it:dp[temp])
            {
                if(--ind[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(ans.size()==num)
        {
            return ans;
        }
        return {};
    }
};