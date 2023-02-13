class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) 
    {
        int n=s.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<min(i+31,n);j++)
            {
                sum=sum<<1|(s[j]-'0');
                if(mp.find(sum)==mp.end())
                {
                    mp[sum]={i,j};
                }
                else 
                {
                    int diff1=abs(mp[sum][1]-mp[sum][0]);
                    int diff2=abs(i-j);
                    if(diff1==diff2)
                    {
                        mp[sum]=min(mp[sum],{i,j});
                    }
                    else if(diff1>diff2)
                    {
                        mp[sum]={i,j};
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(auto it:q)
        {
            int l=it[0];
            int r=it[1];
            int val=l^r;
            if(mp.find(val)!=mp.end())
            {
                ans.push_back(mp[val]);
            }
            else
            {
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};