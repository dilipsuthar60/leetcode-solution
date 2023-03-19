class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int count=0;
         int mp[2100]={0};
        int n=nums.size();
        for(int i=1;i<(1<<n);i++)
        {
            if(__builtin_popcount(i)==1)
            {
                count++;
                continue;
            }
            int f=1;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    if(mp[nums[j]-k+1000]==i)
                    {
                        f=0;
                        break;
                    }
                    mp[nums[j]+1000]=i;
                }
            }
            if(f)
            {
                count++;
            }
        }
        return count;
    }
};