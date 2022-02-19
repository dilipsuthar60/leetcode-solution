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
        int ans=*s.rbegin()-*s.begin();
        while((*s.rbegin())%2==0)
        {
            int last=*s.rbegin();
                s.erase(last);
                s.insert(last/2);
            ans=min(ans,*s.rbegin()-*s.begin());
        }
        return ans;
    }
};