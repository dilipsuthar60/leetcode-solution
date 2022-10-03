class Solution {
public:
    int minCost(string s, vector<int>& cost) 
    {
        int n=s.size();
        stack<pair<char,int>>st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!st.empty()&&st.top().first==s[i])
            {
                if(st.top().second<cost[i])
                {
                    ans+=st.top().second;
                    st.pop();
                    st.push({s[i],cost[i]});
                }
                else
                {
                    ans+=cost[i];
                }
            }
            else
            {
                st.push({s[i],cost[i]});
            }
        }
        return ans;
    }
};