// class Solution {
// public:
    
//     bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLen) {
//         for(int j=0; j<s.size(); j+=wordLen) {
//             string w = s.substr(j, wordLen);
//             if(wordCount.find(w) != wordCount.end()) {
//                 if(--wordCount[w] == -1) {
//                     return false;
//                 }
//             } else {
//                 return false;
//             }
//         }
//         return true;
//     }

//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> res;
//         int wordLen = words[0].size();
//         int sLen = s.size();
//         int wordsWindow = words.size() * wordLen;
        
//         unordered_map<string, int> wordCount;
//         for(int i=0; i<words.size(); i++) {
//             wordCount[words[i]]++;
//         }
        
//         int i = 0;
//         while(i + wordsWindow <= sLen) {
//             if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)) {
//                 res.push_back(i);
//             }
//             i++;
//         }
//         return res;
//     }
// };
class Solution {
public:
    int k;
    bool find(string &s,int &window,unordered_map<string,int>&mp)
    {
        if(s.size()<k)
        {
            return false;
        }
        for(int i=0;i<s.size();i+=window)
        {
            string str=s.substr(i,window);
            if(--mp[str]==-1)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int>mp,new_map;
        int first_len=words[0].size();
        k=words[0].size()*(words.size());
        for(auto &it:words)
        {
            mp[it]++;
        }
        vector<int>ans;
        for(int i=0;i<s.size()-k+1;i++)
        {
            new_map=mp;
            string str=s.substr(i,k);
            if(find(str,first_len,new_map))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};