class Solution {
public:
    int eatenApples(vector<int>& app, vector<int>& day) 
    {
        
        int ans=0;
        multiset<pair<int,int>>pq;
        for(int i=0,n=app.size();i<n||pq.size();i++)
        {
            
            if(i<n&&app[i]>0)
            {
                pq.insert({i+day[i]-1,app[i]});
            }
            while(pq.size()&&(*pq.begin()).first<i)
            {
                pq.erase(pq.begin());
            }
            if(pq.size())
            {
                auto temp=*pq.begin();
                pq.erase(pq.begin());
                if(temp.second>1)
                {
                    pq.insert({temp.first,temp.second-1});
                }
                ans++;
            }
        }
        return ans;
    }
};