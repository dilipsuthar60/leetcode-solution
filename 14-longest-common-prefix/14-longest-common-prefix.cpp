class Solution {
public:
    struct node
    {
        node*child[26]={NULL};
        int count=0;
    };
    node*root=new node();
    void insert(string &s)
    {
        node*curr=root;
        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-97;
            if(curr->child[index]==NULL)
            {
                curr->child[index]=new node();
            }
            curr=curr->child[index];
            curr->count++;
        }
    }
    string longestCommonPrefix(vector<string>& strs)
    {
        for(int i=0;i<strs.size();i++)
        {
            insert(strs[i]);
        }
        string ans="";
        string target=strs.back();
        node*curr=root;
        for(int i=0;i<target.size();i++)
        {
            int index=target[i]-97;
            
            if(curr->child[index]!=NULL&&curr->child[index]->count==strs.size())
            {
                ans.push_back(target[i]);
                curr=curr->child[index];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};