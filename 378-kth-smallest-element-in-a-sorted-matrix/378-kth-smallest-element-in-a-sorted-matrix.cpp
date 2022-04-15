class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int l=mat[0][0];
        int r=mat[n-1][m-1];
        int ans=0;
        auto find=[&](int mid)
        {
            int count=0;
            int j=m-1;
            for(int i=0;i<n;i++)
            {
                while(j>=0&&mat[i][j]>mid)
                {
                    j--;
                }
                count+=(j+1);
            }
            return count;
        };
        while(l<=r)
        {
            int mid=(l+r)/2;
            int val=find(mid);
            if(val>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};