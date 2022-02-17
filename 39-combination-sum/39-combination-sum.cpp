class Solution {
public:
    void find(vector<int>cand,vector<vector<int>>&res,vector<int>&v,int tar,int index)
    {
        if(tar<0)
        {
            return ;
        }
        if(tar==0)
        {
            res.push_back(v);
        }
        for(int i=index;i<cand.size();i++)
        {
            v.push_back(cand[i]);
            find(cand,res,v,tar-cand[i],i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) 
    {    
        vector<vector<int>>res;
        vector<int>v;
        find(cand,res,v,tar,0);
        return res;
    }
};