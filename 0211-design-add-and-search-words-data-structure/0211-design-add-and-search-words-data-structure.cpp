class node
{
    public:
    int end;
    node *child[26];
    node()
    {
        end=0;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
};
class WordDictionary {
public:
    node*root=new node();
    WordDictionary() {
    }
    
    void addWord(string word) 
    {
        node*curr=root;
        for(int i=0;i<word.size();i++)
        {
            if(curr->child[word[i]-'a']==NULL)
            {
                curr->child[word[i]-'a']=new node();
            }
            curr=curr->child[word[i]-'a'];
        }
        curr->end=1;
    }
    bool find(string &s,node*root,int index)
    {
        if(root==NULL)
        {
            return false;
        }
        if(index==s.size())
        {
            return root->end;
        }
        if(s[index]!='.')
        {
            return find(s,root->child[s[index]-'a'],index+1);
        }
        for(int i=0;i<26;i++)
        {
            if(find(s,root->child[i],index+1))
               return true;
        }
        return false;
    }
    bool search(string word) 
    {
        node*curr=root;
        return find(word,curr,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */