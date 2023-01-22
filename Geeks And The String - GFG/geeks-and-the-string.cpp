//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  string find(string s)
  {
      vector<char>stack;
      stack.push_back('1');
      for(int i=0,n=s.size();i<n;i++)
      {
          if(stack.back()!=s[i])
          {
              stack.push_back(s[i]);
          }
          else
          {
              stack.pop_back();
          }
      }
      string curr="";
      for(int i=1;i<stack.size();i++)
      {
          curr+=stack[i];
      }
      return curr;
  }
    string removePair(string s) {
        // code here
        while(true)
        {
            int prev=s.size();
            s=find(s);
            if(prev==s.size())
            {
                break;
            }
        }
        if(s.size()==0)
        {
            return "-1";
        }
        return s;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends