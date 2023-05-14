class Solution {
public:
    vector<int> circularGameLosers(int n, int k) 
    {
        vector<int>vis(n+1,0);
        int i=0;
        int j=1;
        while(true)
        {
            if(vis[i])
            {
                break;
            }
            vis[i]=1;
            i=(i+j*k)%n;
            j++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};