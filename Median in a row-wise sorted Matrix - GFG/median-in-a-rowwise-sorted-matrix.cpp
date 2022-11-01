//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int n, int m){
        // code here          
        int k=(n*m+1)/2;
        int l=0;
        int r=1e8;
        auto find=[&](int target)
        {
          int count=0;
          for(int i=0;i<n;i++)
          {
              count+=upper_bound(mat[i].begin(),mat[i].end(),target)-mat[i].begin();
          }
          return count;
        };
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(mid)>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends