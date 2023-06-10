class Solution {
public:
    vector<int>parent;
    vector<pair<int,int>>path;
    int find_parent(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find_parent(parent[x]);
    }
    int find(int u,int v,int value)
    {
        u=find_parent(u);
        v=find_parent(v);
        if(u==v)
        {
            return 0;
        }
        int count_x=(value==path[u].first)?path[u].second:0;
        int count_y=(value==path[v].first)?path[v].second:0;
        parent[u]=v;
        path[v]={value,count_x+count_y};
        return count_x*count_y;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n=vals.size();
        parent=vector<int>(n+1,0);
        path.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            path[i]={vals[i],1};
        }
        for(int i=0;i<edges.size();i++)
        {
             edges[i].push_back(max(vals[edges[i][0]],vals[edges[i][1]]));
        }
        int count=0;
        sort(edges.begin(),edges.end(),[&](auto &a,auto &b){return a[2]<b[2];});
        for(int i=0;i<edges.size();i++)
        {
            count+=find(edges[i][0],edges[i][1],edges[i][2]);
        }
        return count+n;
    }
};