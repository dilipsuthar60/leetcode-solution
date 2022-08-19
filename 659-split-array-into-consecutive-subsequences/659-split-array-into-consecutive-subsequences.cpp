class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp,present;
        for(auto &it:nums)
        {
            mp[it]++;
        }
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==0)
            {
                continue;
            }
            if(present[nums[i]]>0)
            {
                present[nums[i]]--;
                present[nums[i]+1]++;
            }
            else if(mp[nums[i]]>0&&mp[nums[i]+1]>0&&mp[nums[i]+2]>0)
            {
                mp[nums[i]+1]--;
                mp[nums[i]+2]--;
                present[nums[i]+3]++;
            }
            else
            {
                return false;
            }
            mp[nums[i]]--;
        }
        return true;
    }
};