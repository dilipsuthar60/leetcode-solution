class Solution {
public:
    bool find(int n)
    {
        if(n==1||n==0)
        {
            return 0;
        }
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans=0;
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++)
        {
           if(find(nums[i][i]))
              ans=max(ans,nums[i][i]);
        }
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(find(nums[i][n-i-1]))
            ans=max(ans,nums[i][n-i-1]);
        }
        return ans;
    }
};