class Solution {
public:
    int n;
    vector<int>dp[100005];
    vector<int>find(int node)
    {
        vector<int>dis(n,INT_MAX);
        dis[node]=0;
        queue<int>q;
        q.push(node);
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                dis[temp]=level;
                q.pop();
                for(auto &it:dp[temp])
                {
                    if(dis[it]==INT_MAX)
                      q.push(it);
                }
            }
            level++;
        }
        return dis;
    }
    int closestMeetingNode(vector<int>&nums, int node1, int node2) 
    {
        n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                dp[i].push_back(nums[i]);
            }
        }
        vector<int>dis1=find(node1);
        vector<int>dis2=find(node2);
        int min_dis=INT_MAX;
        int dis=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(dis1[i]!=INT_MAX&&dis2[i]!=INT_MAX)
            {
                dis=min(dis,max(dis1[i],dis2[i]));
                if(dis<min_dis)
                {
                    min_dis=dis;
                    ans=i;
                }
            }
        }
        return ans;
    }
};