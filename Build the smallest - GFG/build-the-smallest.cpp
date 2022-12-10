//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    if(k>=num.size())
    {
        return "0";
    }
    string s;
    for(int i=0;i<num.size();i++)
    {
        while(s.size()&&(s.back()>num[i])&&k)
        {
            k--;
            s.pop_back();
        }
        if(s.size()||num[i]!='0')
        {
            s.push_back(num[i]);
        }
    }
    while(k&&s.size())
    {
        s.pop_back();
        k--;
    }
    if(s.size()==0)
    {
        return "0";
    }
    return s;
}