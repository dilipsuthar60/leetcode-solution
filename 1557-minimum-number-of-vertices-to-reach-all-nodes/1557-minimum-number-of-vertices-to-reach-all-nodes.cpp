class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        int ind[n];
        memset(ind,0,sizeof(ind));
        for(auto it:edges)
        {
            ind[it[1]]++;
        }
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};