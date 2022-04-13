class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>>v(n,vector<int>(n,0));
        int l=0;
        int r=n-1;
        int t=0;
        int b=n-1;
        int div=0;
        int x=1;
        while(l<=r&&t<=b)
        {
            if(div==0)
            {
                for(int i=l;i<=r;i++)
                {
                    v[t][i]=x++;
                }
                t++;
            }
            else if(div==1)
            {
                for(int i=t;i<=b;i++)
                {
                    v[i][r]=x++;
                }
                r--;
            }
            else if(div==2)
            {
                for(int i=r;i>=l;i--)
                {
                    v[b][i]=x++;
                }
                b--;
            }
            else if(div==3)
            {
                for(int i=b;i>=t;i--)
                {
                    v[i][l]=x++;
                }
                l++;
            }
            div=(div+1)%4;
        }
        return v;
    }
};