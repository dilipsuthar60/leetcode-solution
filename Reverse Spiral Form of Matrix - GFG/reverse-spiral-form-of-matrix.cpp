//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void Swap(int &number1,int &number2)
  {
      number1=number1^number2;
      number2=number1^number2;
      number1=number1^number2;
  }
  void reverse(vector<int>&ans)
  {
      int left=0;
      int right=ans.size()-1;
      while(left<right)
      {
          Swap(ans[left],ans[right]);
          left++;
          right--;
      }
  }
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&mat)  {
       
        vector<pair<int,int>>d={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0;
        int y=0;
        int nx=0;
        int ny=0;
        int t=n*m;
        int i=0;
        auto safe=[&](int x,int y)
        {
          return x>=0&&y>=0&&x<n&&y<m&&mat[x][y]!=1e9;  
        };
        vector<int>ans;
        for(int index=0;index<n*m;index++)
        {
            nx=x+d[i].first;
            ny=y+d[i].second;
            if(!safe(nx,ny))
            {
                i=(i+1)%4;
                nx=x+d[i].first;
                ny=y+d[i].second;
            }
            ans.push_back(mat[x][y]);
            mat[x][y]=1e9;
            x=nx;
            y=ny;
        }
        reverse(ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends