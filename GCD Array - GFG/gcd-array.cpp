//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) 
    {
        for(int i=1;i<N;i++)
        {
            arr[i]+=arr[i-1];
        }
        int total=arr.back();
        vector<int>factor;
        for(int i=1;i<=sqrt(total);i++)
        {
            if(total%i==0)
            {
                factor.push_back(i);
                factor.push_back(total/i);
            }
        }
        sort(factor.rbegin(),factor.rend());
        for(auto &value:factor)
        {
            int count=0;
            for(int i=0;i<N;i++)
            {
                if(arr[i]%value==0)
                {
                    count++;
                }
            }
            if(count>=K)
            {
                return value;
            }
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends