class Solution {
public:
    vector<int>rank;
    vector<int>prime;
    const int N=1e5+10;
    vector<int>find(int n)
    {
        vector<int>v;
        while(n>1)
        {
            int f=prime[n];
            v.push_back(f);
            n/=f;
        }
        return v;
    }
    int find_p(int x,vector<int>&parent)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find_p(parent[x],parent);
    }
    void merge(int x,int y,vector<int>&parent)
    {
        x=find_p(x,parent);
        y=find_p(y,parent);
        if(x==y)
        {
            return ;
        }
        if(rank[x]<rank[y])
        {
            rank[y]+=rank[x];
            parent[x]=y;
        }
        else
        {
            rank[x]+=rank[y];
            parent[y]=x;
        }
    }
    bool canTraverseAllPairs(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>parent(n);
        rank=vector<int>(n,1);
        iota(parent.begin(),parent.end(),0);
        prime=vector<int>(N);
        iota(prime.begin(),prime.end(),0);
        for(int i=2;i<N;i++)
        {
            if(prime[i]==i)
            {
                for(int j=2*i;j<N;j+=i)
                {
                    prime[j]=i;
                }
            }
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            for(auto it:find(nums[i]))
            {
                mp[it].push_back(i);
            }
        }
        for(auto &[_,v]:mp)
        {
            for(int i=1;i<v.size();i++)
            {
                merge(v[i-1],v[i],parent);
            }
        }
        unordered_map<int,int>group;
        for(int i=0;i<n;i++)
        {
            group[find_p(i,parent)];
        }
        return group.size()==1;
    }
};