class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) 
    {
        int n=costs.size();
        int i=0;
        int j=n-1;
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        while(pq1.size()<cand&&i<=j)
        {
            pq1.push(costs[i++]);
        }
        while(pq2.size()<cand&&j>=i)
        {
            pq2.push(costs[j--]);
        }
        long long ans=0;
        int count=0;
        while(count<k&&i<=j)
        {
            // cout<<"yes"<<endl;
            int first=pq1.top();
            int second=pq2.top();
            if(first<=second)
            {
                count++;
                ans+=first;
                pq1.pop();
                pq1.push(costs[i++]);
            }
            else
            {
                count++;
                ans+=second;
                pq2.pop();
                pq2.push(costs[j--]);
            }
        }
        while(count<k)
        {
            int first=pq1.size()?pq1.top():1e9;
            int second=pq2.size()?pq2.top():1e9;
            int val=min(first,second);
            if(val==first)
            {
                pq1.pop();
                ans+=first;
            }
            else
            {
                pq2.pop();
                ans+=second;
            }
            count++;
            // if(first<=second)
            // {
            //     // cout<<first<<" ";
            //     count++;
            //     ans+=first;
            //     pq1.pop();
            // }
            // else
            // {
            //     count++;
            //     ans+=second;
            //     pq2.pop();
            // }
        }
        return ans;
    }
};