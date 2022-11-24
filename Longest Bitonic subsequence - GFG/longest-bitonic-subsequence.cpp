//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int>left(n),right(n);
	    set<int>s;
	    for(int i=0;i<n;i++)
	    {
	        auto it=s.lower_bound(nums[i]);
	        if(it!=s.end())
	        {
	            s.erase(it);
	        }
	        s.insert(nums[i]);
	        left[i]=s.size();
	    }
	    s.clear();
	    for(int i=n-1;i>=0;i--)
	    {
	        auto it=s.lower_bound(nums[i]);
	        if(it!=s.end())
	        {
	            s.erase(it);
	        }
	        s.insert(nums[i]);
	        right[i]=s.size();
	    }
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        ans=max(ans,left[i]+right[i]-1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends