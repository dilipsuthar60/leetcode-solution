//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &nums)
    {
        // code here
        sort(nums.begin(),nums.end(),[&](auto a,auto b){return a.size()<b.size();});
        int n=nums.size();
        string ans="";
        unordered_map<string,int>mp{{"",0}};
        int max_val=0;
        for(int i=0;i<n;i++)
        {
            string s=nums[i];
            s.pop_back();
            if(mp.find(s)!=mp.end())
            {
                mp[nums[i]]=nums[i].size();
                max_val=max(max_val,mp[nums[i]]);
            }
        }
      for(auto it:mp)
      {
          if(it.second==max_val)
          {
              if(ans.size()==0)
              {
                  ans=it.first;
              }
              else 
              {
                  ans=min(ans,it.first);
              }
          }
      }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends