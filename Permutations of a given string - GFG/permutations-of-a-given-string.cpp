//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void find(string&s,unordered_map<char,int>&mp,string&curr,vector<string>&ans,int index)
	{
	    if(index==s.size())
	    {
	        ans.push_back(curr);
	        return ;
	    }
	    for(auto &it:mp)
	    {
	        if(it.second==0)
	        {
	            continue;
	        }
	        it.second--;
	        curr.push_back(it.first);
	        find(s,mp,curr,ans,index+1);
	        curr.pop_back();
	        it.second++;
	    }
	}
		vector<string>find_permutation(string s)
		{
		    unordered_map<char,int>mp;
		    for(int i=0;i<s.size();i++)
		    {
		        mp[s[i]]++;
		    }
		    int n=s.size();
		    vector<string>result;
		    string curr="";
		    find(s,mp,curr,result,0);
		    sort(result.begin(),result.end());
		    return result;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends