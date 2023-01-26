//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<int>small(26,0),big(26,0);
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                small[str[i]-'a']++;
            }
            else
            {
                big[str[i]-'A']++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                for(int j=0;j<26;j++)
                {
                    if(small[j]>0)
                    {
                        str[i]=char(j+'a');
                        small[j]--;
                        break;
                    }
                }
            }
            else
            {
                for(int j=0;j<26;j++)
                {
                    if(big[j]>0)
                    {
                        str[i]=char(j+'A');
                        big[j]--;
                        break;
                    }
                }
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends