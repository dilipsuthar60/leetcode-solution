//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// } Driver Code Ends
//User function Template for C++

/*
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
 */


class Solution
{
public:
int ans=0;
int maxgcd=0;
// 2  3  1
// 4  5  1
// 8  9  1
// 6  7  1
// 1
void find(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left!=NULL&&root->right!=NULL)
    {
        int c=__gcd(root->left->data,root->right->data);
        maxgcd=max(maxgcd,c);
    }
    find(root->left);
    find(root->right);
}
void find1(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left!=NULL&&root->right!=NULL)
    {
        int c=__gcd(root->left->data,root->right->data);
        if(maxgcd==c)
        {
            ans=max(ans,root->data);
        }
    }
    find1(root->left);
    find1(root->right);
}
    int maxGCD( Node* root)
    {
        ans=0;
        maxgcd=0;
        if(root==NULL)
        {
            return 0;
        }
        find(root);
        find1(root);
        return ans;
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		Solution ob;
		cout<<ob.maxGCD(root)<<endl;
    }
    return 0;
}

// } Driver Code Ends