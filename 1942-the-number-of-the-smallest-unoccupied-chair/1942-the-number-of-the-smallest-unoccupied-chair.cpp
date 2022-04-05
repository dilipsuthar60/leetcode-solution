class Solution {
public:
    int smallestChair(vector<vector<int>>& nums, int t) 
    {
        int n=nums.size();
        vector<int>v=nums[t];
        sort(nums.begin(),nums.end());
        multiset<pair<int,int>>mp;
        set<int>s;
        int count=0;
        for(int i=0;i<n;i++)
        {
             int seat;
            while(mp.size()>0 &&(*mp.begin()).first<=nums[i][0])
            {
                s.insert((*mp.begin()).second);
                mp.erase(mp.begin());
            }
            if(s.size())
            {
                seat=*s.begin();
                s.erase(s.begin());
            }
            else
            {
                seat=count;
                count++;
            }
             if(v[0]==nums[i][0])
            {
                return seat;
            }
            mp.insert({nums[i][1],seat});
        }
        return n;
    }
};