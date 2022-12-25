class Solution {
public:
     // if(ind==nums.size()){
     //        if(sum<k){
     //            return 1;
     //        }
     //        return 0;    
     //    }
     //    if(dp[ind][sum]!=-1)return dp[ind][sum];
     //    ll take=0;
     //    if(sum+nums[ind]<k)
     //        take=part(ind+1,nums,sum+nums[ind],k,dp);
     //    ll notTake=part(ind+1,nums,sum,k,dp);
     //    return dp[ind][sum]=(take%mod+notTake%mod)%mod;
    int mod=1e9+7;
    int n;
    long long  dp[1001][1001];
    int find(vector<int>&nums,int index,int sum,int k)
    {
        if(sum>=k)
        {
            return 0;
        }
        if(index==n)
        {
            return (1);
        }
        if(dp[index][sum]!=-1)
        {
            return dp[index][sum]%mod;
        }
        long long first=find(nums,index+1,sum+nums[index],k);
        long long second=find(nums,index+1,sum,k);
        return dp[index][sum]= (first+second)%mod;
    }
    int countPartitions(vector<int>& nums, int k) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        if(sum<2*k)
        {
            return 0;
        }
        long long total=1;
        for(int i=0;i<n;i++)
        {
            total<<=1;
            total%=mod;
        }
        long long value=find(nums,0,0,k);
        return (total-2*value+mod)%mod;
    }
};