class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>&mat) 
    {
        int n=mat.size();
        unordered_map<string,bitset<101>>mp;
        for(int i=0;i<n;i++)
        {
            for(auto &it:mat[i])
            {
                mp[it][i]=1;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            bitset<101>temp,temp1;
            temp.set();
            temp1.set();
            for(auto &it:mat[i])
            {
                temp&=mp[it];
            }
            if(temp.count()==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};