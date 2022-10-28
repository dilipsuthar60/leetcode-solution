class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) 
    {
        set<vector<int>>s;
        for(auto &it:pieces)
        {
            s.insert(it);
        }
        vector<int>v;
        for(int i=0;i<arr.size();i++)
        {
            v.push_back(arr[i]);
            if(s.count(v))
            {
                v.clear();
            }
        }
        return !v.size();
    }
};