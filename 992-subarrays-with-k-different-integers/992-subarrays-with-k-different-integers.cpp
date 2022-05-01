class Solution {
public:
    int find(vector<int>&nums,int k)
    {
        int ans=0;
        int n=nums.size();
        int j=0;
        int hash[20005];
        memset(hash,0,sizeof(hash));
        int unique=0;
        for(int i=0;i<n;i++)
        {
            if(hash[nums[i]]==0)
            {
                unique++;
            }
            hash[nums[i]]++;
            while(unique>k)
            {
                hash[nums[j]]--;
                if(hash[nums[j]]==0)
                {
                    unique--;
                }
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return find(nums,k)-find(nums,k-1);
    }
};