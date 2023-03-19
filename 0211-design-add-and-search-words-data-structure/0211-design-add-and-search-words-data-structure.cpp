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
    node*root;
    WordDictionary() {
        root=new node();
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
    bool find(string &s,node*rt,int index)
    {
        if(rt==NULL)
        {
            return false;
        }
        if(index==s.size())
        {
            return rt->end;
        }
        if(s[index]!='.')
        {
            return find(s,rt->child[s[index]-'a'],index+1);
        }
        for(int i=0;i<26;i++)
        {
            if(find(s,rt->child[i],index+1))
            {
                return true;
            }
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