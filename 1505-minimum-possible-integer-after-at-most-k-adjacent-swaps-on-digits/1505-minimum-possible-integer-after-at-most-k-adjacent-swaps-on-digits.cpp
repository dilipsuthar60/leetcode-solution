class Solution {
public:
    int bit[100005];
    int N=100005;
    void update(int i,int val)
    {
        while(i<N)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int find(int i)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    string minInteger(string s, int k) 
    {
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
            update(i,1);
        }
        deque<int>q[10];
        for(int i=0;i<n;i++)
        {
            q[s[i]-'0'].push_back(i+1);
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            for(int d=0;d<10;d++)
            {
                if(q[d].size())
                {
                    auto temp=q[d].front();
                    int val=find(temp-1);
                    // cout<<temp<<"  "<<val<<endl;
                    if(val<=k)
                    {
                        k-=val;
                        ans+=char(d+'0');
                        q[d].pop_front();
                        update(temp,-1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};