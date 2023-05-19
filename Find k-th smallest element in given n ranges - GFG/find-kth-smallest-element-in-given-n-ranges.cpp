//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>>merge(vector<vector<int>>&nums)
    {
        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
            if(ans[j][1]>=nums[i][0])
            {
                ans[j][1]=max(ans[j][1],nums[i][1]);
            }
            else
            {
                ans.push_back(nums[i]);
                j++;
            }
        }
        return ans;
    }
    int find(vector<vector<int>>&nums,int k)
    {
        int value=k;
        for(auto it:nums)
        {
            int current=abs(it[0]-it[1])+1;
            if(k<=current)
            {
                return it[0]+k-1;
            }
            else
            {
                k-=current;
            }
        }
        return -1;
    }
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries)
    {
        
        vector<int>ans;
        sort(range.begin(),range.end());
        vector<vector<int>>nums=merge(range);
        for(int i=0;i<q;i++)
        {
            int value=find(nums,queries[i]);
            ans.push_back(value);
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends