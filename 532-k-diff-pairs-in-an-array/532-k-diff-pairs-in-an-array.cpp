class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &it:nums)
        {
            mp[it]++;
        }
        int count=0;
        for(auto num:mp)
        {
            if((k>0&&mp.find(num.first+k)!=mp.end())||(k==0&&mp[num.first]>1))
            {
                count++;
            }
        }
        return count;
    }
};