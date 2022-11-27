//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    string s;
    int  n=A.size()-1;
    int m=B.size()-1;
    int c=0;
    vector<char>v;
    while(c==1||n>=0||m>=0)
    {
        c+=n>=0?(A[n]-'0'):0;
        c+=m>=0?(B[m]-'0'):0;
        v.push_back((c%2+'0'));
        c=c/2;
        n--;
        m--;
    }
    while(v[v.size()-1]=='0'&&v.size()>1)
    {
        v.pop_back();
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        s+=v[i];
    }
    return s;
	
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends