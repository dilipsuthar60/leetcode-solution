//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long x , y, mn = (long)1e10, ans = 0, tot = 0;
        for(int i = 0; i < N; i++){
            x = A[i];
            y = B[i];
            if(y % 2 == 1)
                y--;
            if(y >= 2){
                mn = min(mn,x);
            }
            ans += y*x;
            tot += y;
        }
        if(tot % 4 != 0){
           ans -= 2l * mn;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends