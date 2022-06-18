class WordFilter
{
public:
    unordered_map<string,int>mp;
    WordFilter(vector<string>&nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            string s=nums[i];
            int len=s.size();
            for(int x=0;x<len;x++)
            {
                string first=s.substr(0,x+1);
                for(int y=0;y<len;y++)
                {
                    string second=s.substr(y);
                    mp[first+"#"+second]=i;
                }
            }
        }
    }
    
    int f(string pref, string suf) 
    {
        string hash=pref+"#"+suf;
        if(mp.find(pref+"#"+suf)!=mp.end())
        {
         return mp[pref+"#"+suf];   
        }
        return -1;
    }
};