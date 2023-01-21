class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        for(int a=1;a<=3;a++)
        {
            for(int b=1;b<=3;b++)
            {
                for(int c=1;c<=3;c++)
                {
                    for(int d=1;d<=3;d++)
                    {
                        if(a+b+c+d==s.size())
                        {
                            int val1=stoi(s.substr(0,a));
                            int val2=stoi(s.substr(a,b));
                            int val3=stoi(s.substr(a+b,c));
                            int val4=stoi(s.substr(a+b+c,d));
                            if(val1<=255&&val2<=255&&val3<=255&&val4<=255)
                            {
                                string curr=to_string(val1)+'.'+to_string(val2)+'.'+to_string(val3)+'.'+to_string(val4);
                                if(curr.size()==s.size()+3)
                                {
                                    ans.push_back(curr);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};