//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>&nums, int n, int k) 
    {
        k++;
        int l=1;
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int sum=0;
            int count=0;
            for(int i=0;i<n;i++)
            {
                sum+=nums[i];
                if(sum>=mid)
                {
                    sum=0;
                    count++;
                }
            }
            if(count>=k)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends