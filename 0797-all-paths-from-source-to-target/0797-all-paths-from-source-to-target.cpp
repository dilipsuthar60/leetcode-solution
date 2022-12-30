class Solution {
public:
    void find(vector<vector<int>>&dp,int src,int target,vector<int>&curr,vector<vector<int>>&result)
    
    {
        // cout<<src<<endl;
        curr.push_back(src);
        if(src==target)
        {
            result.push_back(curr);
            return ;
        }
        for(auto it:dp[src])
        {
            find(dp,it,target,curr,result);
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<int>curr;
        vector<vector<int>>result;
        
          find(graph,0,graph.size()-1,curr,result);
        
        return result;
    }
};