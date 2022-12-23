class Solution {
public:
    int ans=0;
    bool check(int y)
    {
        int x=(int)sqrt(y);
        return (x*x==y);
    }
    void find(vector<int>&nums,unordered_map<int,int>&mp,int index,int prev=-1)
    {
        if(index>=nums.size())
        {
            ans++;
            return ;
        }
        for(auto &[value,freq]:mp)
        {
            if(freq==0)
            {
                continue;
            }
            if((prev==-1)||(check(prev+value)))
            {
                // cout<<"yes"<<endl;
                mp[value]--;
                find(nums,mp,index+1,value);
                mp[value]++;
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) 
    {
        ans=0;
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        find(nums,mp,0);
        return ans;
    }
};