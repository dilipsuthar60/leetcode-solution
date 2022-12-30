class Solution {
public:
    bool is_safe(int node,vector<int>&v)
    {
        for(auto &it:v)
        {
            if(it==node)
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>&nums) 
    {
        vector<vector<int>>ans;
        queue<vector<int>>q;
        q.push({0});
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            int back_element=temp.back();
            if(back_element==nums.size()-1)
            {
                ans.push_back(temp);
            }
            for(auto &it:nums[back_element])
            {
                if(is_safe(it,temp))
                {
                    vector<int>res(temp.begin(),temp.end());
                    res.push_back(it);
                    q.push(res);
                }
            }
        }
        return ans;
    }
};