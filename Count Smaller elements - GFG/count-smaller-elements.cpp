// { Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
vector<int>bit;
int N;
     int find(int i)
     {
         int sum=0;
         while(i>0)
         {
             sum+=bit[i];
             i-=(i&-i);
         }
         return sum;
     }
     void update(int i,int val)
     {
         while(i<N)
         {
             bit[i]+=val;
             i+=(i&-i);
         }
         
     }
	vector<int> constructLowerArray(int *arr, int n) 
	{
	    vector<int>nums;
	    for(int i=0;i<n;i++)
	    {
	        nums.push_back(arr[i]);
	    }
	    vector<int>temp(nums.begin(),nums.end());
	    sort(temp.begin(),temp.end());
	    for(int i=0;i<n;i++)
	    {
	        nums[i]=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin()+1;
	    }
	    N=*max_element(nums.begin(),nums.end())+10;
	    bit.resize(N+1);
	    vector<int>ans;
	    for(int i=n-1;~i;i--)
	    {
	        ans.push_back(find(nums[i]-1));
	        update(nums[i],1);
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends