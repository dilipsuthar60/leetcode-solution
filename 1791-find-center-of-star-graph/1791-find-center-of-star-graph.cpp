class Solution {
public:
    int findCenter(vector<vector<int>>& nums) 
    {
        map<int,int>mp;
        mp[nums[0][0]]++;
        mp[nums[0][1]]++;
        mp[nums[1][0]]++;
        mp[nums[1][1]]++;
        int ans=-1;
        for(auto it:mp)
        {
            if(it.second==2)
            {
                return it.first;
            }
        }
        return -1;
    }
};