/*
class Bitset {
public:
    string s = "", fliped = "";
    
    int cnt1 = 0;
    int size = 0;
    
    Bitset(int size) 
    {
        for(int i=0; i<size; i++)
        {
            s.push_back('0');
            fliped.push_back('1');
        }
        
        this->size = size;
    }
    
    void fix(int ind) 
    {
        if(s[ind] == '0')
            cnt1++;
        
        s[ind] = '1';
        fliped[ind] = '0'; 
    }
    
    void unfix(int ind) 
    {
        if(s[ind] == '1')
            cnt1--;
        s[ind] = '0';
        fliped[ind] = '1';
    }
    
    void flip() 
    {
        s.swap(fliped); // Updated After reading comments 
        // swap(s, fliped);
        cnt1 = size - cnt1;
    }
    
    bool all() 
    {
        return cnt1 == size;
    }
    
    bool one() 
    {
        return cnt1;
    }
    
    int count() 
    {
        return cnt1;
    }
    
    string toString() 
    {
        return s;
    }
};

*/
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
    void Swap(string &s1,string&s2)
    {
        temp=s1;
        s1=s2;
        s2=temp;
    }
    void flip()
    {
        Swap(s,f);
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

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */