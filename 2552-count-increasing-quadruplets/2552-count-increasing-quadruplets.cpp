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
        for(int i=1;i<n-2;i++)
        {
            vector<int>bitl(4100);
            vector<int>bitr(4100);
            for(int j=i+1;j<n;j++)
            {
                update(nums[j],1,bitr);
            }
            for(int j=0;j<i;j++)
            {
                update(nums[j],1,bitl);
            }
            for(int j=i+1;j<n-1;j++)
            {
                update(nums[j],-1,bitr);
                if(nums[i]>nums[j])
                {
                    int left=find(nums[j]-1,bitl);
                    int right=find(4005,bitr)-find(nums[i],bitr);
                    ans+=(left*right);
                }
            }
        }
        return ans;
    }
};