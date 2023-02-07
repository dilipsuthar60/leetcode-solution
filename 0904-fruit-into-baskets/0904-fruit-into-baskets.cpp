class Solution {
public:
    int totalFruit(vector<int>&nums) 
    {
        int n=nums.size();
        int hash[n+1];
        memset(hash,0,sizeof(hash));
        int ans=0;
        int j=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(hash[nums[i]]==0)
            {
                count++;
            }
            hash[nums[i]]++;
            while(count>2)
            {
                hash[nums[j]]--;
                if(hash[nums[j]]==0)
                {
                    count--;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};