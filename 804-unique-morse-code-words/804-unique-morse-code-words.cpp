class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        set<string>mp;
        vector<string>v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto it:words)
        {
            string s="";
            for(int i=0;i<it.size();i++)
            {
                int index=it[i]-97;
                s=s+v[index];
            }
            mp.insert(s);
            // mp[s]++;
        }
        return mp.size();
    }
};