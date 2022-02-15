// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int mod=M;
		    long long int res=1;
		    while(n)
		    {
		        if(n&1)
		        {
		            res=(res*x)%mod;
		        }
		        x=(x*x)%mod;
		        n=n/2;
		    }
		    return res;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends