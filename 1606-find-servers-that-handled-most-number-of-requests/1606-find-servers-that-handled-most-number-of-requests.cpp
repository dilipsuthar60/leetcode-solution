class Solution {
public:
    vector<int> busiestServers(int k, vector<int>&arrival, vector<int>& load) 
    {
        int n=arrival.size();
        set<int>free;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++)
        {
            free.insert(i);
        }
        for(int i=0;i<n;i++)
        {
            while(pq.size()&&pq.top().first<=arrival[i])
            {
                free.insert(pq.top().second);
                pq.pop();
            }
            if(free.size())
            {
                auto it=free.lower_bound(i%k);
                if(it==free.end())
                {
                    it=free.begin();
                }
                mp[*it]++;
                pq.push({arrival[i]+load[i],*it});
                free.erase(*it);
            }
        }
        int maxLoad=0;
        for(auto &it:mp)
        {
            maxLoad=max(maxLoad,it.second);
        }
        vector<int>ans;
        for(auto it:mp)
        {
            if(it.second==maxLoad)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};