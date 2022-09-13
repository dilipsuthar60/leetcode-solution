class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int ans=0;
        int sum=0;
        for(auto &[a,b]:mp)
        {
            sum+=b;
            b=sum;
            ans=max(ans,b);
        }
        return ans;
    }
};