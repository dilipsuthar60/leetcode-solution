class Solution {
public:
    vector<int>parent,rank;
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        // if(rank[x]>rank[y])
        // {
        //     parent[y]=x;
        // }
        // else if(rank[x]<rank[y])
        // {
        //     parent[x]=y;
        // }
        // else
        // {
        //     rank[x]++;
            parent[x]=y;
        // }
    }
    vector<int> groupStrings(vector<string>&nums) 
    {
        int n=nums.size();
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
        unordered_map<int,int>mp,del;
        for(int i=0;i<n;i++)
        {
            int hash=0;
            for(auto &it:nums[i])
            {
                hash|=(1<<(it-97));
            }
            for(int j=0;j<26;j++)
            {
                if((hash&(1<<j)))
                {
                    int new_hash=(hash^(1<<j));
                    if(mp.find(new_hash)!=mp.end())
                    {
                        merge(mp[new_hash],i);
                    }
                    if(del.find(new_hash)!=del.end())
                    {
                        merge(del[new_hash],i);
                    }
                    else
                    {
                        del[new_hash]=i;
                    }
                }
                else
                {
                    int new_hash=(hash|(1<<j));
                    if(mp.find(new_hash)!=mp.end())
                    {
                        merge(mp[new_hash],i);
                    }
                }
            }
            mp[hash]=i;
        }
        unordered_map<int,int>result;
        int max_group=0;
        for(int i=0;i<n;i++)
        {
            int val=find(i);
            result[val]++;
            max_group=max(max_group,result[val]);
        }
        return {(int)result.size(),max_group};
    }
};