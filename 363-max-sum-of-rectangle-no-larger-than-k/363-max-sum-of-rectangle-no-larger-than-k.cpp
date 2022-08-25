class Solution {
public:
    int n,m;
    int find(int nums[],int k)
    {
        set<int>s;
        s.insert(0);
        int sum=0;
        int ans=-1e8;
        for(int i=0;i<m;i++)
        {
            sum+=nums[i];
            auto it=s.lower_bound(sum-k);
            if(it!=s.end())
            {
                ans=max(ans,sum-*it);
            }
            s.insert(sum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& mat, int K) 
    {
        n=mat.size();
        m=mat[0].size();
        int ans=-1e8;
        for(int i=0;i<n;i++)
        {
            int nums[m];
            memset(nums,0,sizeof(nums));
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    nums[k]+=mat[j][k];
                }
                ans=max(ans,find(nums,K));
            }
        }
        return ans;
    }
};