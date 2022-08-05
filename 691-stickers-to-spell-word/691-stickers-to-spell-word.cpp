class Solution {
public:
    int tlen;
    int n;
    int dp[51][1<<15];
    int present=0;
    int find(vector<string>&nums,int index,int mask,string &target)
    {
        if(mask==((1<<tlen)-1))
        {
            present=1;
            return 0;
        }
        if(index>=n)
        {
            return 1e8;
        }
        if(dp[index][mask]!=-1)
        {
            return dp[index][mask];
        }
        int ans=1e8;
        int yes=0;
        vector<int>mp(26,0);
        for(int i=0;i<nums[index].size();i++)
        {
            mp[nums[index][i]-'a']++;
        }
        for(int i=0;i<tlen;i++)
        {
            if(((mask&(1<<i))==0)&&mp[target[i]-'a']>0)
            {
                yes=1;
                break;
            }
        }
        if(yes)
        {
            int new_mask=mask;
            for(int i=0;i<tlen;i++)
            {
                if(((new_mask&(1<<i))==0)&&mp[target[i]-'a']>0)
                {
                    new_mask|=(1<<i);
                    mp[target[i]-'a']--;
                }
            }
            ans=min(ans,1+find(nums,index,new_mask,target));
        }
        ans=min(ans,find(nums,index+1,mask,target));
        return dp[index][mask]= ans;
    }
    int minStickers(vector<string>&str, string tt) 
    {
        present=0;
        tlen=tt.size();
        n=str.size();
        memset(dp,-1,sizeof(dp));
       int val=find(str,0,0,tt);
        if(present)
        {
            return val;
        }
        return -1;
        // int vis[1<<16];
        // memset(vis,0,sizeof(vis));
        // int tlen=tt.size();
        // int tmask=(1<<tlen)-1;
        // queue<int>q;
        // q.push(0);
        // int level=0;
        // auto find=[&](int val)
        // {
        //     string s;
        //     while(val)
        //     {
        //         s.push_back(val%2+'0');
        //         val/=2;
        //     }
        //     reverse(s.begin(),s.end());
        //     cout<<s<<endl;
        // };
        // while(q.size())
        // {
        //     int size=q.size();
        //     while(size--)
        //     {
        //         auto temp=q.front();
        //         q.pop();
        //         find(temp);
        //         if(temp==tmask)
        //         {
        //             return level;
        //         }
        //         if(vis[temp])
        //         {
        //             continue;
        //         }
        //         vis[temp]=1;
        //         for(auto &val:dp)
        //         {
        //             int mask=temp;
        //             for(int j=0;j<tlen;j++)
        //             {
        //                 if(((mask&(1<<j))==0)&&val[tt[j]-'a']>0)
        //                 {
        //                     mask|=(1<<j);
        //                     val[tt[j]-'a']--;
        //                 }
        //             }
        //             q.push(mask);
        //         }
        //     }
        //     level++;
        // }
        // return -1;
    }
};