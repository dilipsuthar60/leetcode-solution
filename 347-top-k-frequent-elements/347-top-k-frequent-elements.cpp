class Solution {
public:
     static bool cmp(pair<int,int>&x,pair<int,int>&y)
     {
       if(x.second==y.second)
         return x.first>y.second;
       return x.second>y.second;
     }
    vector<int> topKFrequent(vector<int>& nums, int k)
    {   
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++)
      {
        mp[nums[i]]++;
      }
      vector<pair<int,int>>v(mp.begin(),mp.end());
      sort(v.begin(),v.end(),cmp);
      vector<int>v1;
      for(int i=0;i<k;i++)
      {
        v1.push_back(v[i].first);
      }
      return v1;
    }
};