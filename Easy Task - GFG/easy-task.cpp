//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     vector<vector<int>> seg;
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        seg.resize(4*n);
        for(int i=0;i<4*n;i++){
            seg[i].resize(26);
        }
        buildTree(s,0,0,n-1);
        vector<char> ans;
        for(int i=0;i<q;i++){
            if(queries[i][0]=="1"){
                int ind=stoi(queries[i][1]);
                char val=queries[i][2][0];
                update(0,0,n-1,ind,val);
            }
            else{
                int l=stoi(queries[i][1]);
                int r=stoi(queries[i][2]);
                int k=stoi(queries[i][3]);
                vector<int> arr=query(0,0,n-1,l,r);
                for(int j=25,count=0;j>=0;j--){
                    count+=arr[j];
                    if(count>=k)
                    {
                        ans.push_back(char(j+'a'));
                        break;
                    }
                }
            }
        }
        return ans;
    }
    void buildTree(string a,int si,int ss,int se){
		if(ss==se){
			seg[si][a[ss]-'a']++;
			return;
		}
		int mid=(ss+se)/2;
		buildTree(a,2*si+1,ss,mid);
		buildTree(a,2*si+2,mid+1,se);
        vector<int> a1=seg[2*si+1];
        vector<int> a2=seg[2*si+2];
        for(int i=0;i<26;i++){
            seg[si][i]=a1[i]+a2[i];
        }
	}
    void update(int si,int ss,int se,int pos,char val){
		if(ss==se){
            int in=0;
            for(int i=0;i<26;i++){
                if(seg[si][i]>=1){
                    in=i;
                    break;
                }
            }
            seg[si][in]--;
			seg[si][val-'a']++;
			return;
		}
		int mid=(ss+se)/2;
		if(pos<=mid){
			update(2*si+1,ss,mid,pos,val);
		}else{
			update(2*si+2,mid+1,se,pos,val);
		}
		vector<int> a1=seg[2*si+1];
        vector<int> a2=seg[2*si+2];
        for(int i=0;i<26;i++){
            seg[si][i]=a1[i]+a2[i];
        }
	}
    vector<int> query(int si,int ss,int se,int qs,int qe)
	{
	    vector<int> a(26);
		if(qs>se || qe<ss) return a;
		if(ss>=qs && se<=qe)return seg[si];
		int mid=(ss+se)/2;
		vector<int> a1=query(2*si+1,ss,mid,qs,qe);
		vector<int> a2=query(2*si+2,mid+1,se,qs,qe);
        vector<int> ans(26);
        for(int i=0;i<26;i++){
            ans[i]=a1[i]+a2[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends