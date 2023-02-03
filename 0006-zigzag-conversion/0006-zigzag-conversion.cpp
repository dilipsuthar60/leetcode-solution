class Solution {
public:
    string convert(string s, int num)
    {    
        if(num==1)
        {
            return s;
        }
        vector<string>v(num,"");
        int row=0;
        int d=1;
        for(int i=0;i<s.size();i++)
        {
            v[row].push_back(s[i]);
            row+=d;
            if(row==num-1)
                d=-1;
            if(row==0)
               d=1;
        }
        string str;
        for(auto&it:v)
        {
            str.append(it);
        }
        return str;
    }
};