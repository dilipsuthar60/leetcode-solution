//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        // Write your code here.
                int a=0,b=0,c=0;
        for(int i=n-1;i>=0;i--){
            int x=a,y=b,z=c;
            a=colors[i][0]+min(y,z);
            b=colors[i][1]+min(x,z);
            c=colors[i][2]+min(x,y);
        }
        return min(a,min(b,c));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends