class Solution {
public:
    vector<int> findOriginalArray(vector<int>&arr)
    {
           int n=arr.size();
        if(n%2)
        {
            return {};
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        vector<int>v;
        sort(arr.begin(),arr.end());
        for(auto it:arr)
        {
            if(mp[it]==0)
            {
                continue;
            }
            if(mp[2*it]==0)
            {
                return {};
            }
            mp[2*it]--;
            mp[it]--;
            v.push_back(it);
        }
        return v;
    }
};