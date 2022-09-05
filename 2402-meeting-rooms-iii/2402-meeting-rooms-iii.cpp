class Solution {
public:
    int mostBooked(int n, vector<vector<int>>&nums) 
    {
        sort(nums.begin(),nums.end());
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
       int mp[1001];
        memset(mp,0,sizeof(mp));
        for(auto &val:nums)
        {
            int start=val[0];
            int end=val[1];
            while(pq.size()&&pq.top().first<=start)
            {
                s.insert(pq.top().second);
                pq.pop();
            }
            if(s.size())
            {
                int empty_room=*s.begin();
                s.erase(s.begin());
                mp[empty_room]++;
                pq.push({end,empty_room});
            }
            else
            {
                auto temp=pq.top();
                pq.pop();
                int empty_room=temp.second;
                mp[empty_room]++;
                pq.push({1ll*temp.first+(end-start),empty_room});
            }
        }
        int max_index=0;
        for(int i=0;i<n;i++)
        {
            if(mp[i]>mp[max_index])
            {
                max_index=i;
            }
        }
        return max_index;
    }
};