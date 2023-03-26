//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
         set<int> s;
        for(int i=0;i<N;i++){
         if(s.find(frogs[i])!=s.end()) continue;
         int k=frogs[i];
         while(frogs[i]<=leaves) {
          s.insert(frogs[i]);
          frogs[i]+=k;
         }
        }
        return leaves-s.size();
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends