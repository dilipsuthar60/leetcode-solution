//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string s){
        // code here
        stack<Node*>st;
	for(int i=0;i<s.size();i++)
	{

		int index=i;
		if(s[i]==')')
		{
			st.pop();
		}
		else if(s[i]>='0'&&s[i]<='9')
		{
			while(s[i+1]>='0'&&s[i]<='9')
			{
				i++;
			}
			int value=stoi(s.substr(index,i-index+1));
			Node*node=new Node(value);
			if(st.size())
			{
				Node*parent=st.top();
				if(parent->left==NULL)
				{
					parent->left=node;
				}
				else
				{
					parent->right=node;
				}
			}
				st.push(node);
		}
	}
	return st.top();
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends