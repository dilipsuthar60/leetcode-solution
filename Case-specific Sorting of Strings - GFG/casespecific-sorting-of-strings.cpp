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
        vector<char>small,big;
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                small.push_back(str[i]);
            }
            else
            {
                big.push_back(str[i]);
            }
        }
        int index1=0;
        int index2=0;
        sort(small.begin(),small.end());
        sort(big.begin(),big.end());
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
            {
                str[i]=small[index1++];
            }
            else
            {
                str[i]=big[index2++];
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