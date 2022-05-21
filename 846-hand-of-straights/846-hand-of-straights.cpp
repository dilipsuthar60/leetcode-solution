class Solution {
public:
    bool isNStraightHand(vector<int>&nums, int W)
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        while(mp.size()>0)
        {
            auto it=mp.begin()->first;
            for(int i=it;i<it+W;i++)
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