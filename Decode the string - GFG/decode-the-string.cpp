//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s)
    {
         string ans="";
        stack<int>digit;
        stack<string>str;
        int num=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                num=num*10+(s[i]-'0');
            }
            else if(isalpha(s[i]))
            {
               ans.push_back(s[i]);
            }
            else if(s[i]=='[')
            {
                str.push(ans);
                digit.push(num);
                num=0;
                ans="";
            }
            else if(s[i]==']')
            {
                string temp=ans;
                for(int i=0;i<digit.top()-1;i++)
                {
                    ans+=temp;
                }
                ans=str.top()+ans;
                str.pop();
                digit.pop();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends