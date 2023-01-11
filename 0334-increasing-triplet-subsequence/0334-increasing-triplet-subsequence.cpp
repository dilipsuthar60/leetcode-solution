class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int n=nums.size();
        set<int>s;
        for(int i=0;i<n;i++)
        {
            auto it=s.lower_bound(nums[i]);
            if(it!=s.end())
            {
                s.erase(it);
            }
            s.insert(nums[i]);
        }
        return s.size()>=3;
        // vector<int>left(n,0);
        // vector<int>right(n,0);
        // left[0]=INT_MAX;
        // for(int i=1;i<n;i++)
        // {
        //     left[i]=min(nums[i])
        // }
    }
};