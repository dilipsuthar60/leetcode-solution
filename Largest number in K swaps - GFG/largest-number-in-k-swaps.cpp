// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps
    void find(string s,int k,int index,string&ans)
    {
        if(k==0)
        {
            return ;
        }
        int max_digit=0;
        for(int i=index;i<s.size();i++)
        {
            max_digit=max(max_digit,s[i]-'0');
        }
        if(s[index]-'0'!=max_digit)
        {
            k--;
        }
        for(int i=index;i<s.size();i++)
        {
            if(s[i]-'0'==max_digit)
            {
                swap(s[index],s[i]);
               if (s.compare(ans) > 0)
                   ans = s;
                find(s,k,index+1,ans);
                swap(s[index],s[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        string ans=str;
        find(str,k,0,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends