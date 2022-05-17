class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>&nums, int st) 
    {
        map<int, int> m{{0, 0}};
        for(auto& f:nums){
            m[f[0]]+=f[2];
            m[f[1]+1]-=f[2];
        }
        
        int sum = 0;
        for(auto& [v,c]:m)
            c = sum+=c;
vector<int>persons(st);
        iota(persons.begin(),persons.end(),1);
        vector<int> ans;
        for(int t:persons){
            ans.push_back(prev(m.upper_bound(t))->second);
        }
        return ans;
    }
};