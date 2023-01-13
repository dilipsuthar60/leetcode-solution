class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) 
    {
        int n=s.size();
        vector<int>left(26,1e9),right(26,-1e9);
        for(int i=0;i<n;i++)
        {
            left[s[i]-'a']=min(left[s[i]-'a'],i);
            right[s[i]-'a']=max(right[s[i]-'a'],i);
        }
        vector<pair<int,int>>v;
        for(int i=0;i<26;i++)
        {
            if(left[i]!=1e9)
            {
                int start=left[i];
                int end=right[i];
                for(int i=start;i<=end;i++)
                {
                    start=min(start,left[s[i]-'a']);
                    end=max(end,right[s[i]-'a']);
                }
                if(start==left[i])
                {
                    v.push_back({end,start});
                }
            }
        }
        vector<string>ans;
        sort(v.begin(),v.end());
        int prev=-1;
        for(const auto &[end,start]:v)
        {
            if(start>prev)
            {
                ans.push_back(s.substr(start,end-start+1));
                prev=start;
            }
        }
        return ans;
    }
};