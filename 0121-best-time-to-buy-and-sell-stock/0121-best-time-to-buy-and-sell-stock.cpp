class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int cost=0;
        int curr_min=1e8;
        for(int i=0,n=prices.size();i<n;i++)
        {
            curr_min=min(curr_min,prices[i]);
            cost=max(cost,prices[i]-curr_min);
        }
        return cost;
    }
};