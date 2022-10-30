//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	 long long int solve (int i){
        if(i==1)return 1;
        if(i<=0)return 0;
        return 3*solve(i-1)- 2*solve(i-6);
    }
    long long int NoOfChicks(int n){
        return solve(n)-solve(n-6);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends