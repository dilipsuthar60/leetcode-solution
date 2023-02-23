//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int find(vector<int>&nums,int k)
  {
      int j=0;
      int n=nums.size();
      int mp[100004];
      memset(mp,0,sizeof(mp));
      int count=0;
      int un=0;
      for(int i=0;i<n;i++)
      {
          if(mp[nums[i]]==0)
          {
              un++;
          }
          mp[nums[i]]++;
          while(un>k)
          {
              mp[nums[j]]--;
              if(mp[nums[j]]==0)
              {
                  un--;
              }
              j++;
          }
          count+=(i-j+1);
      }
      return  count;
  }
    int subarrayCount(vector<int> &arr, int N, int k) {

        return find(arr,k)-find(arr,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends