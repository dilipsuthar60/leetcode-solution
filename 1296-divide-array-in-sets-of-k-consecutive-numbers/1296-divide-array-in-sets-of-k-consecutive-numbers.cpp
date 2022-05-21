class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k)
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(;mp.size()>0;)
        {
            auto it=mp.begin()->first;
            for(int i=it;i<it+k;i++)
            {
                if(mp.find(i)==mp.end())
                {
                    return false;
                }
                if(mp[i]==1)
                {
                    mp.erase(i);
                }
                else
                {
                    mp[i]--;
                }
            }
        }
        return true;
    }
};