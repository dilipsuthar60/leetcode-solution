class Solution {
public:
    int find(vector<int>&nums,int index,vector<int>&storeOverlappingSubProblem)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        // check this point value exist or not over current storage 
        if(storeOverlappingSubProblem[index]!=-1)
        {
            // return  this storage value
            return storeOverlappingSubProblem[index];
        }
        int robTakeThisPointGold=nums[index]+find(nums,index+2,storeOverlappingSubProblem);
        int robNotTakeThisPointGold=find(nums,index+1,storeOverlappingSubProblem);
        return storeOverlappingSubProblem[index] = max(robTakeThisPointGold,robNotTakeThisPointGold);
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>storeOverlappingSubProblem(n+1,-1);
        return find(nums,0,storeOverlappingSubProblem);
        // if(nums.size()==1)
        // {
        //     return nums[0];
        // }
        // int n=nums.size();
        // int prev2=nums[0];
        // int prev1=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++)
        // {
        //     int temp=prev1;
        //     prev1=max(prev1,prev2+nums[i]);
        //     prev2=temp;
        // }
        // return prev1;
        // vector<int>dp(n+1,0);
        // dp[0]=nums[0];
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++)
        // {
        //     dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        // }
        // return dp[n-1];
    }
};