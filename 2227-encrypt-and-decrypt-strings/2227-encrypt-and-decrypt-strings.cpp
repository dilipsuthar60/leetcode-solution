class Encrypter {
public:
    unordered_map<char,string>mp1;
    unordered_map<string ,int>mp2;
    Encrypter(vector<char>& key, vector<string>& val, vector<string>& dict) 
    {
        mp1.clear();
        mp2.clear();
        for(int i=0;i<key.size();i++)
        {
            mp1[key[i]]=val[i];
        }
        for(auto &it:dict)
        {
            mp2[encrypt(it)]++;
        }
    }
    
    string encrypt(string word1) {
        string s="";
        for(auto &it:word1)
        {
            if(mp1.find(it)==mp1.end())
            {
                return "";
            }
            s.append(mp1[it]);
        }
        return s;
    }
    
    int decrypt(string word2) {
        return mp2[word2];
    }
};