class Solution {
public:
    map<pair<vector<int>,int>,int>mp;
    int find(vector<int>&nums,int index,vector<int>&w,int num)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(mp.find({w,index})!=mp.end())
        {
            return mp[{w,index}];
        }
        int ans=INT_MIN;
        for(int i=1;i<=num;i++)
        {
            if(w[i]<2)
            {
                w[i]++;
                ans=max(ans,(i&nums[index])+find(nums,index+1,w,num));
                w[i]--;
            }
        }
        return mp[{w,index}]=ans;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) 
    {
        vector<int>w(numSlots+1,0);
        return find(nums,0,w,numSlots);
    }
};