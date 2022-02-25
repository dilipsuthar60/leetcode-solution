class Bitset {
public:
    int n;
    string temp="";
    string s="";
    string f="";
    int count_one=0;
    Bitset(int size) 
    {
        n=size;
        s=string(n,'0');
        f=string(n,'1');
    }
    
    void fix(int idx) 
    {
        if(s[idx]=='0')
        {
            count_one++;
        }
        s[idx]='1';
        f[idx]='0';
    }
    
    void unfix(int idx) 
    {
          if(s[idx]=='1')
        {
            count_one--;
        }
        s[idx]='0';
        f[idx]='1';
    }
    void flip()
    {
        s.swap(f);
        count_one=n-count_one;
    }
    
    bool all() {
        return count_one==n;
    }
    
    bool one() {
        return count_one;
    }
    
    int count() 
    {    
        return count_one;
    }
    
    string toString() {
        return s;
    }
};