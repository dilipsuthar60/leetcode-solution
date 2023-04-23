class Solution {
public:
    int find(map<int,int>&mp,int x)
    {
        int count=0;
        for(auto &[a,b]:mp)
        {
            count+=b;
            if(count>=x)
            {
                return a>0?0:a;
            }
        }
        return -1;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
    {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
        }
        vector<int>v;
        v.push_back(find(mp,x));
        for(int i=k;i<n;i++)
        {
            mp[nums[i-k]]--;
            mp[nums[i]]++;
            v.push_back(find(mp,x));
        }
        return v;
    }
};