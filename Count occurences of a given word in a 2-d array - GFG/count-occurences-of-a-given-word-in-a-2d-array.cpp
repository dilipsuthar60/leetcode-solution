// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int find(vector<vector<char>>&v,int i,int j,string &s,int index)
    {
        if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]!=s[index])
        {
            return 0;
        }
        if(index==s.size()-1)
        {
            return 1;
        }
        int x=0;
        char ch=v[i][j];
        v[i][j]='*';
        x=find(v,i-1,j,s,index+1)+find(v,i+1,j,s,index+1)+find(v,i,j-1,s,index+1)+find(v,i,j+1,s,index+1);
        v[i][j]=ch;
        return x;
    }
    
    int findOccurrence(vector<vector<char> >&mat, string target)
    {
        int count=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                 count+=find(mat,i,j,target,0);
                 
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}
  // } Driver Code Ends