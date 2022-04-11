class Solution {
public:
    string minimizeResult(string s) 
    {
        int n=s.size();
        int p=s.find('+');
        int min_product=INT_MAX;
        string ans="";
        for(int i=0;i<p;i++)
        {
            for(int j=p+1;j<n;j++)
            {
                string s1=s.substr(0,i);
                string s2=s.substr(i,p-i);
                string s3=s.substr(p+1,j-p);
                string s4=s.substr(j+1);
                int n1=s1==""?1:stoi(s1);
                int n2=stoi(s2);
                int n3=stoi(s3);
                int n4=s4==""?1:stoi(s4);
                if(n1*(n2+n3)*n4<min_product)
                {
                    min_product=n1*(n2+n3)*n4;
                    ans=s1+"("+s2+"+"+s3+")"+s4;
                }
            }
        }
        return ans;
    }
};