class Solution {
public:
//       vector<int>v1,v2;
//     int n,dp[15][40000];
    
//     int f(int i, int mask){
//         if(i>=n)return 0;
//         if(dp[i][mask]!=-1)return dp[i][mask];
//         int ans=INT_MAX;
//         for(int k=0;k<n;k++){
//             if(mask&(1<<k))continue;
//             int val=(v1[i]^v2[k])+f(i+1,mask|(1<<k));
//             ans=min(ans,val);
//         }
//         return dp[i][mask]=ans;
//     }
    
//     int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
//         this->v1=nums1;this->v2=nums2;
//         n=v1.size();
//         memset(dp,-1,sizeof dp);
//         return f(0,0);
    int n,m;
    int dp[15][1<<15];
    int find(vector<int>&nums1,vector<int>&nums2,int index,int mask)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index][mask]!=-1)
        {
            return dp[index][mask];
        }
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            if((mask&(1<<i))==0)
            {
                ans=min(ans,(nums1[index]^nums2[i])+find(nums1,nums2,index+1,mask|(1<<i)));
            }
        }
        return dp[index][mask]= ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        memset(dp,-1,sizeof(dp));
        return find(nums1,nums2,0,0);
    }
};