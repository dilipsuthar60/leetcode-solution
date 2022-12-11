//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[(nums[i]+k)%k]++;
        }
        for(int i=0;i<n;i++)
        {
            int rem=(nums[i]+k)%k;
            if(rem==0)
            {
                if(mp[rem]&1)
                {
                    return false;
                }
            }
            else
            {
                if(mp[rem]!=mp[k-rem])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends