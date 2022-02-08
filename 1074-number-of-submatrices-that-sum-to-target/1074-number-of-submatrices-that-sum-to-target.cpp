class Solution {
public:
    unordered_map<int,int>mp;
    int find(int *v,int n,int x)
    {
        mp.clear();
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(mp.find(sum-x)!=mp.end())
            {
                count+=mp[sum-x];
            }
            mp[sum]++;
        }
        // cout<<count<<endl;
        return count;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target)
    {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        int v[m];
        for(int i=0;i<n;i++)
        {
            fill(v,v+m,0);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    v[k]+=mat[j][k];
                }
                ans+=find(v,m,target);
               
            }
        }
        return ans;
    }
};