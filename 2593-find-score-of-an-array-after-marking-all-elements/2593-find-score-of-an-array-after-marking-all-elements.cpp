class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        int n=nums.size();
        set<pair<int,int>>s;
        for(int i=0;i<n;i++)
        {
            s.insert({nums[i],i});
        }
        long long cost=0;
        while(s.size())
        {
            auto [val,index]=*s.begin();
            s.erase(s.begin());
            cost+=val;
            if(index+1<n)
            {
                s.erase({nums[index+1],index+1});
            }
            if(index-1>=0)
            {
                s.erase({nums[index-1],index-1});
            }
        }
        return cost;
    }
};