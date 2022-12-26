class Solution {
public:
    int mod=1e9+7;
    unordered_map<string,long long>dp;
    vector<vector<int>>result;
    void allColor(vector<int>&nums,int index,int m,vector<int>curr)
    {
        if(index==m)
        {
            result.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(curr.size()==0||curr.back()!=nums[i])
            {
                curr.push_back(nums[i]);
                allColor(nums,index+1,m,curr);
                curr.pop_back();
            }
        }
    }
    string get(vector<int>&v)
    {
        string s;
        for(int i=0;i<v.size();i++)
        {
            s.push_back(char(v[i]+'0'));
        }
        return s;
    }
    bool check(string &p,string &s)
    {
        if(p.size()==0)
        {
            return true;
        }
        for(int i=0;i<p.size();i++)
        {
            if(p[i]==s[i])
            {
                return false;
            }
        }
        return true;
    }
    long long find(int n,int index,string prev)
    {
        if(n==index)
        {
            return 1;
        }
        string hash=to_string(index)+"#"+prev;
        if(dp.find(hash)!=dp.end())
        {
            return dp[hash]%mod;
        }
        long long ans=0;
        for(auto &it:result)
        {
            string curr=get(it);
            if(check(prev,curr))
            {
                ans+=find(n,index+1,curr);
            }
        }
        return dp[hash] =ans%mod;
    }
    int colorTheGrid(int m, int n) {
        vector<int>nums={1,2,3};
        vector<int>curr;
        allColor(nums,0,m,curr);
        return (int)find(n,0,"")%mod;
    }
};