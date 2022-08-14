class Solution {
public:
    
    unordered_map<string,vector<string>>parent;
    unordered_map<string,int>dist;
    vector<vector<string>>ans;
    
    void dfs(string curr,vector<string>&path){
        if(curr == "root"){
            ans.push_back(path);
            return;
        }

        for(auto par:parent[curr]){        
            path.push_back(curr);
            dfs(par,path);
            path.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         
        for(auto s:wordList){
            dist[s] = INT_MAX;
            parent[s] = {};
        }
        
        dist[beginWord] = 1;
        parent[beginWord] = {"root"};
        
        queue<string>q;
        q.push(beginWord);
        
        while(!q.empty()){
            
            string currWord = q.front();
            q.pop();
            
            if(currWord == endWord){
                break;
            }
            
            for(int i=0;i<currWord.size();i++){
                string newWord = currWord;
                for(auto ch='a';ch<='z';ch++){
                    
                    newWord[i] = ch;
                    
                    if(newWord != currWord && dist.count(newWord)){
                        if(dist[newWord] > dist[currWord] + 1){
                            dist[newWord] = 1 + dist[currWord];
                            parent[newWord].clear();
                            parent[newWord].push_back(currWord);
                            q.push(newWord);
                        }
                        else if(dist[newWord] == dist[currWord] + 1){
                            parent[newWord].push_back(currWord);
                        }
                    } 
                }   
            }
             
        }   
        
        vector<string>path;
        
        dfs(endWord,path);
        
        for(auto &vec:ans){
            reverse(vec.begin(),vec.end());
        }

        return ans;
    }
};