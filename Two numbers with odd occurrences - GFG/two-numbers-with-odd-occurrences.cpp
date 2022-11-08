//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long total=0;
        for(int i=0;i<N;i++)
        {
            total^=Arr[i];
        }
        long long int  least=total&(-total);
        long long int  first=0;
        long long int  second=0;
        for(int i=0;i<N;i++)
        {
            if(Arr[i]&least)
            {
                first^=Arr[i];
            }
            else
            {
                second^=Arr[i];
            }
        }
        vector<long long int >v={first,second};
        sort(v.rbegin(),v.rend());
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends