class Solution {
public:
    int find(string &s)
    {
        int count=0;
        istringstream ss(s);
        string ans;
        while(getline(ss,ans,' '))
        {
            count++;
        }
        return count;
    }
    string largestWordCount(vector<string>& mess, vector<string>& send)
    {
        string ans="";
        map<string,int>mp;
        for(int i=0;i<send.size();i++)
        {
            mp[send[i]]+=find(mess[i]);
        }
        int val=0;
        for(auto &[a,b]:mp)
        {
            val=max(val,b);
        }
        for(auto &[a,b]:mp)
        {
            if(val==b)
            {
                ans=max(ans,a);
            }
        }
        return ans;
    }
};