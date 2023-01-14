class Solution {
public:
    int find(int x,vector<int>&parent)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
       vector<int>parent(26);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            int x=find(s1[i]-'a',parent);
            int y=find(s2[i]-'a',parent);
            parent[max(x,y)]=min(x,y);
        }
        for(int i=0;i<baseStr.size();i++)
        {
            int val=find(baseStr[i]-'a',parent);
            baseStr[i]=char(val+'a');
        }
        return baseStr;
    }
};