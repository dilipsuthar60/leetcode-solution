//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int>h,v;
            h.push_back(0);
            h.push_back(n+1);
            v.push_back(0);
            v.push_back(m+1);
            for(auto &it:enemy)
            {
                h.push_back(it[0]);
                v.push_back(it[1]);
            }
            sort(h.begin(),h.end());
            sort(v.begin(),v.end());
            int first=0;
            int second=0;
            for(int i=1;i<h.size();i++)
            {
                first=max(first,h[i]-h[i-1]-1);
            }
            for(int i=1;i<v.size();i++)
            {
                second=max(second,v[i]-v[i-1]-1);
            }
            return first*second;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends