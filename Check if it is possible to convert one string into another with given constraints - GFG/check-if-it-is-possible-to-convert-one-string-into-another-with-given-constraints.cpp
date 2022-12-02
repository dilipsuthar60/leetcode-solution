//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int m, int n) {
        // code here
        if(m != n) return 0;
        string s1 = "";
        string s2 = "";
        for(int i=0; i<m; i++) {
            if(S[i] != '#') s1.push_back(S[i]);
            if(T[i] != '#') s2.push_back(T[i]);
        }
        return s1 == s2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends