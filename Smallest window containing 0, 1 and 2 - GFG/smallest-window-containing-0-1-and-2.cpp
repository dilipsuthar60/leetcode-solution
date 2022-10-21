//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int ans=1e9;
        int first=-1;
        int second=-1;
        int third=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                first=i;
            }
            if(s[i]=='1')
            {
                second=i;
            }
            if(s[i]=='2')
            {
                third=i;
            }
            if(first!=-1&&second!=-1&&third!=-1)
            {
                ans=min(ans,i-min({first,second,third})+1);
            }
        }
        if(ans==1e9)
        {
            return -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends