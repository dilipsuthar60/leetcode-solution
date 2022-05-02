// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        vector<int>p,t;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='P')
            {
                p.push_back(i);
            } 
            else if(arr[i]=='T')
            {
                t.push_back(i);
            }
        }
        int ans=0;
        int l=0;
        int r=0;
        while(l<p.size()&&r<t.size())
        {
            if(abs(p[l]-t[r])<=k)
            {
                ans++;
                l++;
                r++;
            }
            else if(t[r]<p[l])
            {
                r++;
            }
            else
            {
                l++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends