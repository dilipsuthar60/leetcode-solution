//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) 
    {
        int len=0;
        int j=0;
        multiset<int>s;
        for(int i=0;i<N;i++)
        {
            s.insert(arr[i]);
            while(*s.rbegin()-*s.begin()>1)
            {
                s.erase(s.find(arr[j++]));
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends