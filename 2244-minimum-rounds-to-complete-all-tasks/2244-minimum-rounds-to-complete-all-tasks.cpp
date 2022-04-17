class Solution {
public:
     int find(vector<int>& c, int x)
    {
        vector<int>v(x+1,x+1);
        v[0]=0;
        int n=c.size();
        for(int i=1;i<=x;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(c[j]<=i)
                {
                    v[i]=min(v[i],v[i-c[j]]+1);
                }
            }
        }
        return v[x]==x+1?-1:v[x];
    }
    int minimumRounds(vector<int>& tasks) 
    {
        map<int,int>mp;
        for(auto &it:tasks)
        {
            mp[it]++;
        }
        vector<int>v;
        for(auto it:mp)
        {
        v.push_back(it.second);
        }
        vector<int>c={2,3};
        int count=0;
        for(int i=0,n=v.size();i<n;i++)
        {
            
            int val=find(c,v[i]);
            if(val==-1)
            {
                return -1;
            }
            count+=val;
        }
        return count;
    }
};