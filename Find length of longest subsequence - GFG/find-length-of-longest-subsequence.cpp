// { Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}// } Driver Code Ends


int maxSubsequenceSubstring(string s1, string s2, int n, int m)
{
    int max_len=0;
    for(int i=0;i<m;i++)
    {
        int k=i;
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(s1[j]==s2[k])
            {
                k++;
                count++;
            }
        }
        max_len=max(count,max_len);
    }
    return max_len;
}