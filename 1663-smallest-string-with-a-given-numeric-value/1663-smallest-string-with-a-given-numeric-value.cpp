class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string s(n,'a');
        k=k-n;
        int i=s.size()-1;
        while(k>0)
        {
            int mn=min(k,25);
            s[i]+=mn;
            i--;
            k=k-mn;
        }
        return s;
    }
};