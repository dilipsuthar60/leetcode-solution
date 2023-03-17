class Trie {
public:
    /** Initialize your data structure here. */
    struct node
    {
        node*child[26]={NULL};
        int end=0;
    };
    node*root;
    Trie() 
    {
        root=new node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        node*curr=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-97;
            if(curr->child[ind]==NULL)
            {
                curr->child[ind]=new node();
            }
            curr=curr->child[ind];
        }
        curr->end=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        node*curr=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-97;
            if(curr->child[ind]==NULL)
            {
                return false;
            }
            curr=curr->child[ind];
        }
        return curr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word)
    {
        node*curr=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-97;
            if(curr->child[ind]==NULL)
            {
                return false;
            }
            curr=curr->child[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */