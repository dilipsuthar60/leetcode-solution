class Solution {
public:
    int ans=1e8;
    void find(vector<int>&nums,vector<int>&v,int k,int index)
    {
        if(index>=nums.size())
        {
            int mx=-1e8;
            for(int i=0;i<k;i++)
            {
                mx=max(v[i],mx);
            }
            ans=min(ans,mx);
            return ;
        }
        for(int i=0;i<k;i++)
        {
            v[i]+=nums[index];
            find(nums,v,k,index+1);
            v[i]-=nums[index];
        }
    }
    int distributeCookies(vector<int>&nums, int k) 
    {
        vector<int>v(k);
        find(nums,v,k,0);
        return ans;
    }
};