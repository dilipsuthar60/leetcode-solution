class Solution {
public:
    int find(int i,vector<int>&bit)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    void update(int i,int value,vector<int>&bit)
    {
        while(i<4100)
        {
            bit[i]+=value;
            i+=(i&-i);
        }
    }
    long long countQuadruplets(vector<int>& nums) 
    {
        long long ans=0;
        int n=nums.size();
        for(int k=1;k<n-2;k++)
        {
            vector<int>bitl(4100);
            vector<int>bitr(4100);
            for(int j=k+1;j<n;j++)
            {
                update(nums[j],1,bitr);
            }
            for(int j=0;j<k;j++)
            {
                update(nums[j],1,bitl);
            }
            for(int j=k+1;j<n-1;j++)
            {
                update(nums[j],-1,bitr);
                if(nums[j]<nums[k])
                {
                    int left=find(nums[j]-1,bitl);
                    int right=find(4005,bitr)-find(nums[k],bitr);
                    ans+=(left*right);
                }
            }
        }
        return ans;
    }
};