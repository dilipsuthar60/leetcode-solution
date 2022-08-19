
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]-1)==mp.end())
            {
                mp[nums[i]].push(1);
            }
            else
            {
                auto temp=mp[nums[i]-1].top();
                mp[nums[i]-1].pop();
                if(mp[nums[i]-1].size()==0)
                {
                    mp.erase(nums[i]-1);
                }
                mp[nums[i]].push(temp+1);
            }
        }
        for(auto &[a,b]:mp)
        {
            if(b.top()<3)
            {
                return false;
            }
        }
        return true;
    }
};