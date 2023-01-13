class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]=1;
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto index=q.front();
                q.pop();
                if(index==n-1)
                {
                    return level;
                }
                if(index-1>=0&&vis[index-1]==0)
                {
                    q.push(index-1);
                    vis[index-1]=1;
                }
                if(index+1<n&&vis[index+1]==0)
                {
                    q.push(index+1);
                    vis[index+1]=1;
                }
                for(auto &it:mp[arr[index]])
                {
                    if(vis[it]==0)
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
                mp.erase(arr[index]);
            }
            level++;
        }
        return -1;
    }
};