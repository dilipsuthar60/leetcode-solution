class Solution {
public:
    int carFleet(int t, vector<int>& pos, vector<int>& sd) 
    {
        map<int,double,greater<int>>mp;
        for(int i=0;i<pos.size();i++)
        {
            mp[pos[i]]=(double)(t-pos[i]+0.0)/(sd[i]+0.0);
        }
        int count=0;
        double curr=0;
        for(auto &[p,s]:mp)
        {
            if(s>curr)
            {
                curr=s;
                count++;
            }
        }
        return count;
    }
};