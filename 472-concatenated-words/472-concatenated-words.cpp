// class Solution {
// private:
//     struct Trie
//     {
//         vector<Trie*> children{26};
//         bool end{false};
//     };
    
//     Trie* root;
    
//     void insert(string& s)
//     {
//         if (s.empty()) return;
//         Trie* cur = root;
//         for (char c:s)
//         {
//             if (cur->children[c-'a'] == nullptr)
//                 cur->children[c-'a'] = new Trie();
//             cur = cur->children[c-'a'];
//         }
//         cur->end = true;
//     }
    
//     bool dfs(Trie* root, Trie* node, string& word, int idx, int count)
//     {
//         if (!node)
//             return false;
        
//         if (idx >= word.size())
//         {
//             if (node->end && count >=1 )
//                 return true;
//             else
//                 return false;
//         }
        
//         if (node->end && dfs(root, root, word, idx, count+1))
//             return true;
//         return dfs(root, node->children[word[idx]-'a'], word, idx+1, count);
//     }
    
// public:
//     vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//         sort(words.begin(), words.end(), [](const string& w1, const string& w2) {
//             return w1.size() < w2.size();
//         });
        
//         vector<string> ret;
//         root = new Trie();
        
//         for(auto &w: words)
//         {
//             if (w.empty()) continue;
//             if(dfs(root, root, w, 0, 0)) 
//                 ret.push_back(w);
//             else 
//                 insert(w);
//         }
    
//         return ret;
//     }
// };
class Solution {
public:
    struct node
    {
        node*child[26]={NULL};
        int end=0;
    };
    node*root=new node();
    void insert(string s)
    {
        int n=s.size();
        node*curr=root;
        for(int i=0;i<n;i++)
        {
            if(curr->child[s[i]-'a']==NULL)
            {
                curr->child[s[i]-'a']=new node();
            }
            curr=curr->child[s[i]-'a'];
        }
        curr->end=1;
    }
    bool find(node* root,node* curr,int index,string &s,int count)
    {
        if(!curr)
        {
            return false;
        }
        if(index>=s.size())
        {
            if(curr->end&&count>=1)
            {
                return true;
            }
            return false;
        }
        if(curr->end&&find(root,root,index,s,count+1))
        {
            return true;
        }
        return find(root,curr->child[s[index]-'a'],index+1,s,count);
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& nums) 
    {
        vector<string>ans;
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a.size()<b.size();});
        for(auto &s:nums)
        {
            if(find(root,root,0,s,0))
            {
                ans.push_back(s);
            }
            else
            {
                insert(s);
            }
        }
        return ans;
    }
};