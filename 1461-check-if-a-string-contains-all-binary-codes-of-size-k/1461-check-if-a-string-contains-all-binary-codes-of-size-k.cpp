class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        
        int size=1<<k;
        unordered_set<int>st;
        int allone=size-1;
        int hash=0;
        
        for(int i=0,n=s.size();i<n;i++)
        {
            hash=((hash<<1)&(allone))|(s[i]-'0');
            if(i>=k-1)
            {
                st.insert(hash);
            }
        }
        return st.size()==size;
    }
};