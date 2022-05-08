class Solution {
public:
    string largestGoodInteger(string num) 
    {
        string s="";
        for(int i=0;i+2<num.size();i++)
        {
            string str=num.substr(i,3);
            set<char>vis(str.begin(),str.end());
            if(str.size()==3&&vis.size()==1)
            {
                s=max(str,s);
            }
                
        }
        return s;
    }
};