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
        for(int j=1;j<n-2;j++)
        {
            vector<int>bitl(4500),bitr(4500);
            for(int i=0;i<j;i++)
            {
                update(nums[i],1,bitl);
            }
            for(int i=j+1;i<n;i++)
            {
                update(nums[i],1,bitr);
            }
            for(int k=j+1;k<n-1;k++)
            {
                update(nums[k],-1,bitr);
                if(nums[j]>nums[k])
                {
                    int left=find(nums[k]-1,bitl);
                    int right=find(4005,bitr)-find(nums[j],bitr);
                    ans+=left*right;
                }
            }
        }
        return ans;
    }
};