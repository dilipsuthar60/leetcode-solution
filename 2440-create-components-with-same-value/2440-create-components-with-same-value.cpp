class Solution {
public:
    vector<int>nums;
    vector<int>dp[20005];
    int  find(int node,int val,int &comp,int p=-1)
    {
        int sum=nums[node];
        for(auto it:dp[node])
        {
            if(it!=p)
            {
                sum+=find(it,val,comp,node);
            }
        }
        if(sum==val)
        {
            comp++;
            return 0; 
        }
        return sum;
    }
    int componentValue(vector<int>& N, vector<vector<int>>& edges) 
    {
        this->nums=N;
        for(auto it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        int ans=0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=1;i<=sqrt(sum);i++)
        {
            if(sum%i==0)
            {
                int comp=0;
                if(find(0,i,comp)==0)
                {
                    ans=max(ans,comp);
                }
                comp=0;
                if(find(0,sum/i,comp)==0)
                {
                    ans=max(ans,comp);
                }
            }
        }
        return ans-1;
    }
};