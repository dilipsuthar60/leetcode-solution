class Solution {
public:
    int n;
    vector<int>dp[100005];
    int vis[100005];
    int depth[100005];
    void cycle(int x,int d,int &start,int &end,int &cycle_len)
    {
        vis[x]=1;
        depth[x]=d;
        for(auto &it:dp[x])
        {
            if(vis[it]==0)
            {
                cycle(it,d+1,start,end,cycle_len);
            }
            else if(vis[it]==1)
            {
                // cout<<"YES"<<endl;
                cycle_len=max(cycle_len,depth[x]-depth[it]+1);
                start=x;
                end=it;
            }
        }
        vis[x]=2;
    }
    int maximumInvitations(vector<int>& nums) 
    {
        n=nums.size();
        int indegree[n];
        memset(indegree,0,sizeof(indegree));
        for(int i=0;i<n;i++)
        {
            dp[i].push_back(nums[i]);
            indegree[nums[i]]++;
        }
        queue<int>q;
        vector<int>len(n,0);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size())
        {
            auto temp=q.front();
            // vis[temp]=1;
            q.pop();
            for(auto it:dp[temp])
            {
                len[it]=len[temp]+1;
                if(--indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        int ans1=0; 
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int start=-1;
                int end=-1;
                int cycle_len=0;
                cycle(i,0,start,end,cycle_len);
                // cout<<cycle_len<<"  "<<start<<" "<<end<<endl;
                if(cycle_len==2)
                {
                    ans1+=(2+len[start]+len[end]);
                }
                else
                {
                    ans=max(ans,cycle_len);
                }
            }
        }
        return max(ans1,ans);
    }
};