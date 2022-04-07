// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/


 // } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        unordered_map<int,int>trc;
        unordered_map<int,Node*>mp;
        Node*root=NULL;
        vector<vector<int>>nums;
        for(int i=0;i<N;i++)
        {
            if(trc.find(parent[i])==trc.end())
            {
                nums.push_back({parent[i],i,1});
            }
            else
            {
                nums.push_back({parent[i],i,0});
            }
            trc[parent[i]]++;
        }
        for(auto &it:nums)
        {
            int p=it[0];
            int c=it[1];
            int is_left=it[2];
            if(mp.find(p)==mp.end())
            {
                 Node*new_node=new Node(p);
                 mp[p]=new_node;
            }
            if(mp.find(c)==mp.end())
            {
                 Node*new_node=new Node(c);
                 mp[c]=new_node;
            }
            if(is_left)
            {
                mp[p]->left=mp[c];
            }
            else
            {
                  mp[p]->right=mp[c];
            }
        }
        return mp[-1]->left;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
            
        Solution ob;
        
        Node *res = ob.createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends