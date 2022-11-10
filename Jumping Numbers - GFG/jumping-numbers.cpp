//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        queue<long long>q;
        for(int i=0;i<10;i++)
        {
            q.push(i);
        }
        vector<int>v;
        while(1)
        {
            auto temp=q.front();
            q.pop();
            if(temp>X)
            {
                break;
            }
            v.push_back(temp);
            int last_digit=temp%10;
            if(last_digit>0)
            {
                q.push(temp*10+last_digit-1);
            }
            if(last_digit<9)
            {
                q.push(temp*10+last_digit+1);
            }
        }
        sort(v.begin(),v.end());
        return v.back();
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends