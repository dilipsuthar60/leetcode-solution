//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<pair<long long,long long >>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({-arr[i],i});
        }
        sort(v.begin(),v.end());
        set<long long>s;
        vector<long long >ans(n,-1);
        for(auto t:v)
        {
            long long i=t.second;
            auto it=s.lower_bound(i);
            if(it!=s.end())
            {
                ans[i]=arr[*it];
            }
            s.insert(i);
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
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends