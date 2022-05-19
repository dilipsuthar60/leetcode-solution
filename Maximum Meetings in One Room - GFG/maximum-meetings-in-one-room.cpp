// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
static bool cmp(vector<int>&a,vector<int>&b)
{
    if(a[1]!=b[1])
            {
                return a[1]<b[1];
            }
            return a[2]<b[2];
}
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &f)
    {
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({s[i],f[i],i});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        int last=0;
        for(int i=0;i<n;i++)
        {
            int start=v[i][0];
            int end=v[i][1];
            int index=v[i][2];
            if(i==0)
            {
                ans.push_back(index+1);
                last=end;
            }
            else if(start>last)
            {
                ans.push_back(index+1);
                last=end;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends