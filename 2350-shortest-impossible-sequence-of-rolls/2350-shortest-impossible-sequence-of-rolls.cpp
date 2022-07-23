class Solution {
public:
    int shortestSequence(vector<int>& nums, int k) {
        unordered_set<int>s;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
            if(s.size()==k)
            {
                ans++;
                s.clear();
            }
        }
        // for(int i=1;i<=k;i++)
        // {
        //     if(s.find(i)==s.end())
        //     {
        //         return ans+1;
        //     }
        // }
        return ans+1;
    }
};