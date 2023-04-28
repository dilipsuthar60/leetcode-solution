class Solution {
public:
    int find(int x,vector<int>&parent)
    {
        if(-1==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    bool check(string &s1,string&s2)
    {
        if(s2.size()!=s1.size())
        {
            return false;
        }
        int n=s1.size();
        int count=0;
        if(s1==s2)
        {
            return true;
        }
        for(int i=0;i<n&&count<=2;i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
            }
        }
        return count==2;
    }
    int numSimilarGroups(vector<string>& s) 
    {
        int n=s.size();
        vector<int>parent(n+1,0);
        for(int i=0;i<n+1;i++)
        {
            parent[i]=-1;
        }
        int count=n;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(check(s[i],s[j]))
                {
                    int x=find(i,parent);
                    int y=find(j,parent);
                    if(x!=y)
                    {
                        parent[x]=y;
                      count--;
                    }
                }
            }
        }
        return count;
    }
};