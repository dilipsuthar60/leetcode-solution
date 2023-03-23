//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{
public:
bool find(Node*root,vector<Node*>&v,int target)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==target){
        v.push_back(root);
        return true;
    }
    if(find(root->left,v,target)||find(root->right,v,target)){
        v.push_back(root);
        return true;
    }
    return false;
}
void find1(Node*root,int sum,int &min_sum)
{
    if(root==NULL)
    {
        return ;
    }
    sum+=root->data;
    if(root->left==NULL&&root->right==NULL)
    {
        min_sum=min(min_sum,sum);
        // return ;
    }
    find1(root->left,sum,min_sum);
    find1(root->right,sum,min_sum);
}
    int maxDifferenceBST(Node *root,int target)
    {
        vector<Node*>v;
        bool f=find(root,v,target);
        if(f==false)
        {
            return -1;
        }
        int first=0;
        int second=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]->data!=target)
            {
                first+=v[i]->data;
            }
        }
        Node*now=v.front();
        int min_sum1=1e9;
        int min_sum2=1e9;
        if(now->left==NULL&&now->right==NULL)
        {
            return first;
        }
        find1(now->left,0,min_sum1);
        find1(now->right,0,min_sum2);
        return first-min(min_sum1,min_sum2);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends