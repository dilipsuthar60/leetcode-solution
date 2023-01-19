//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
    bool check(string s)
    {
        if(s.size()==0)
        {
            return false;
        }
        if(s[0]=='0'&&s.size()>=2)
        {
            return false;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<'0'||s[i]>'9')
            {
                return false;
            }
        }
        int value=stoi(s);
        if(value<0||value>255)
        {
            return 0;
        }
        return true;
    }
        int isValid(string s) 
        {
            vector<string>v;
            stringstream ss(s);
            string ans;
            int count=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='.')
                {
                    count++;
                }
            }
            if(count!=3)
            {
                return false;
            }
            while(getline(ss,ans,'.'))
            {
                v.push_back(ans);
            }
            if(v.size()!=4)
            {
                return 0;
            }
            for(auto it:v)
            {
                if(!check(it))
                {
                    return false;
                }
            }
            return true;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends