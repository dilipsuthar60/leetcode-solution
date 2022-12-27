class Solution {
public:
    int mod=1e9+7;
    long long dp[5001][15];
    vector<vector<int>>result;
    void allColor(vector<int>&nums,int index,vector<int>curr)
    {
        // if(index==3)
        // {
        //     result.push_back(curr);
        //     return ;
        // }
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(curr.size()==0||curr.back()!=nums[i])
        //     {
        //         curr.push_back(nums[i]);
        //         allColor(nums,index+1,curr);
        //         curr.pop_back();
        //     }
        // }
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    if(i!=j&&j!=k)
                    {
                        result.push_back({i,j,k});
                    }
                }
            }
        }
    }
    // long long find(int &n,int index,int a,int b,int c)
    // {
    //     if(n==index)
    //     {
    //         return 1;
    //     }
    //     if(dp[index][a][b][c]!=-1)
    //     {
    //         return dp[index][a][b][c]%mod;
    //     }
    //     long long ans=0;
    //     for(auto &t:result)
    //     {
    //         if(t[0]!=a&&t[1]!=b&&t[2]!=c)
    //         {
    //             ans+=find(n,index+1,t[0],t[1],t[2]);
    //         }                      
    //     }
    //     return dp[index][a][b][c] = ans%mod;
    // }
    long long find2(vector<vector<int>>&result,int curr,int index,int &n)
    {
        if(index==n)
        {
            return 1;
        }
        if(dp[index][curr]!=-1)
        {
            return dp[index][curr]%mod;
        }
        long long ans=0;
        for(int i=0;i<result.size();i++)
        {
            int yes=1;
            for(int k=0;k<result[0].size();k++)
            {
                if(result[curr][k]==result[i][k])
                {
                    yes=0;
                    break;
                }
            }
            if(yes)
            {
                ans+=find2(result,i,index+1,n);
            }
        }
        return dp[index][curr] =ans%mod;
    }
    int numOfWays(int n) {
        vector<int>nums={1,2,3};
        vector<int>curr;
        allColor(nums,0,curr);
        memset(dp,-1,sizeof(dp));
        long long ans=0;
        for(int i=0;i<result.size();i++)
        {
            ans+=find2(result,i,1,n);
            ans%=mod;
        }
        // return find(n,0,0,0,0)%mod;
        return (int)ans;
    }
};