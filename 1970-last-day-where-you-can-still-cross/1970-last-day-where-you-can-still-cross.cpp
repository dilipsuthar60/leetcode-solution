class Solution {
public:
    vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
    bool find(vector<vector<int>>&mat,int n,int m,int day)
    {
        vector<vector<int>>nums(n,vector<int>(m,0));
        for(int i=0;i<day;i++)
        {
            nums[mat[i][0]-1][mat[i][1]-1]=1;
        }
        queue<int>q;
        for(int i=0;i<m;i++)
        {
            if(nums[0][i]==0)
            {
                q.push(0*m+i);
                nums[0][i]=1;
            }
        }
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            int x=temp/m;
            int y=temp%m;
            if(x==n-1)
            {
                return true;
            }
            for(auto it:d)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&nums[nx][ny]==0)
                {
                    q.push(nx*m+ny);
                    nums[nx][ny]=1;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int n, int m, vector<vector<int>>&mat) 
    {
        int ans=0;
        int l=1;
         int r=n*m;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(find(mat,n,m,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};