class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        int n=nums.size();
        set<int>s;
        for(auto &it:nums)
        {
            if(it&1)
            {
                it*=2;
            }
            s.insert(it);
        }
        int ans=INT_MAX;
        while(true)
        {
            int first=*s.begin();
            int last=*s.rbegin();
            ans=min(ans,last-first);
            if(last%2==0)
            {
                s.erase(s.find(last));
                s.insert(last/2);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};