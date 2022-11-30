class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
      map<int,int>mp;
      set<int>s;
      for(int i=0;i<arr.size();i++)
      {
        mp[arr[i]]++;
      }
      int count=0;
      for(auto it=mp.begin();it!=mp.end();it++)
      {
        if(s.find(it->second)!=s.end())
          return false;
        s.insert(it->second);
      }
      return true;

    }
};