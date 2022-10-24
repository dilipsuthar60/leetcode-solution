class Solution {
public:
    int maxLength(vector<string>&nums) 
    {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++)
        {
            int mask=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    for(auto &it:nums[j])
                    {
                        int index=(it-'a');
                        if(mask&(1<<index))
                        {
                            mask=0;
                            break;
                        }
                        else
                        {
                            mask|=(1<<index);
                        }
                    }
                }
            }
            ans=max(ans,__builtin_popcount(mask));
        }
        return ans;
    }
};