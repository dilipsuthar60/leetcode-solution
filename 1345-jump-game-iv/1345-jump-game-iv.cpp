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
    // int n = arr.size();
    //     unordered_map<int, vector<int>> indicesOfValue;
    //     for (int i = 0; i < n; i++)
    //         indicesOfValue[arr[i]].push_back(i);
    //     vector<bool> visited(n); visited[0] = true;
    //     queue<int> q; q.push(0);
    //     int step = 0;
    //     while (!q.empty()) {
    //         for (int size = q.size(); size > 0; --size) {
    //             int i = q.front(); q.pop();
    //             if (i == n - 1) return step; // Reached to last index
    //             vector<int>& next = indicesOfValue[arr[i]];
    //             next.push_back(i - 1); next.push_back(i + 1);
    //             for (int j : next) {
    //                 if (j >= 0 && j < n && !visited[j]) {
    //                     visited[j] = true;
    //                     q.push(j);
    //                 }
    //             }
    //             next.clear(); // avoid later lookup indicesOfValue arr[i]
    //         }
    //         step++;
    //     }
    //     return 0;