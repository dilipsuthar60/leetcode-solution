class Solution {
public:
    string discountPrices(string s, int dis)
    {
        istringstream ss(s);
        string ans;
        vector<string>v;
        while(getline(ss,ans,' '))
        {
            v.push_back(ans);
        }
        for(auto &it:v)
        {
            int c=0;
            int d=0;
            for(int i=0;i<it.size();i++)
            {
                if(it[i]=='$')
                {
                    c++;
                }
                if(it[i]>='0'&&it[i]<='9')
                {
                    d++;
                }
            }
            if(it[0]=='$'&&c==1&&d==it.size()-1)
            {
                if(it.size()==1)
                {
                    continue;
                }
                long long val=0;
                val=stoll(it.substr(1));
                double vt=((val*(100-dis)*1.0+0.5)/(100.000));
                string curr=to_string(vt);
                // if(vt>(double)1.000&&dis==100)
                // {
                //     curr="0.00";
                // }
                int index=curr.find('.'); 
                it='$'+curr.substr(0,index+1)+curr.substr(index+1,2);
            }
        }
        string res;
        for(auto &it:v)
        {
            res+=it+" ";
        }
        res.pop_back();
        return res;
    }
};