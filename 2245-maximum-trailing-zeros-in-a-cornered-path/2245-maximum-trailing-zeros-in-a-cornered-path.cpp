class Solution {
public:
    pair<int,int>find(int n)
    {
        int count2=0;
        int count5=0;
        while(n%2==0)
        {
            n=n/2;
            count2++;
        }
        while(n%5==0)
        {
            n=n/5;
            count5++;
        }
        return {count2,count5};
        
    }
    int maxTrailingZeros(vector<vector<int>>&mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<vector<int>>>nums(2,vector<vector<int>>(n,vector<int>(m,0)));
        vector<vector<vector<int>>>top(2,vector<vector<int>>(n,vector<int>(m,0)));
        vector<vector<vector<int>>>left(2,vector<vector<int>>(n,vector<int>(m,0)));
        vector<vector<vector<int>>>right(2,vector<vector<int>>(n,vector<int>(m,0)));
        vector<vector<vector<int>>>bottom(2,vector<vector<int>>(n,vector<int>(m,0)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                auto it=find(mat[i][j]);
                nums[0][i][j]=it.first;
                nums[1][i][j]=it.second;
            }
        }
        top=left=right=bottom=nums;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i)
                {
                    top[0][i][j]+=top[0][i-1][j];
                    top[1][i][j]+=top[1][i-1][j];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j)
                {
                    left[0][i][j]+=left[0][i][j-1];
                    left[1][i][j]+=left[1][i][j-1];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(j!=m-1)
                {
                    right[0][i][j]+=right[0][i][j+1];
                    right[1][i][j]+=right[1][i][j+1];
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                if(i!=n-1)
                {
                    bottom[0][i][j]+=bottom[0][i+1][j];
                    bottom[1][i][j]+=bottom[1][i+1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int curr2=nums[0][i][j];
                int curr5=nums[1][i][j];
                
                int top2=top[0][i][j];
                int top5=top[1][i][j];
                
                int right2=right[0][i][j];
                int right5=right[1][i][j];
                
                int bottom2=bottom[0][i][j];
                int bottom5=bottom[1][i][j];
                
                int left2=left[0][i][j];
                int left5=left[1][i][j];
                
                ans=max(ans,min(top2+right2-curr2,top5+right5-curr5));
                ans=max(ans,min(top2+left2-curr2,top5+left5-curr5));
                ans=max(ans,min(bottom2+right2-curr2,bottom5+right5-curr5));
                ans=max(ans,min(bottom2+left2-curr2,bottom5+left5-curr5));
            }
        }
        return ans;
    }
};