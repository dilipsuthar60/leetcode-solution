class Solution {
public:
    set<vector<int>>st;
    // void find(vector<int>nums,vector<int>&res,vector<vector<int>>&v,int index)
    // {
    //     if(res.size()>=2)
    //     {
    //         if(st.find(res)==st.end())
    //         {
    //             st.insert(res);
    //            v.push_back(res);
    //         }
    //     }
    //     for(int i=index;i<nums.size();i++)
    //     {
    //         if(res.size()==0||nums[i]>=res[res.size()-1])
    //         {
    //             res.push_back(nums[i]);
    //             find(nums,res,v,i+1);
    //             res.pop_back();
    //         }
    //     }
    // }
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        st.clear();
        vector<vector<int>>v;
        // find(nums,res,v,0);
        // return v;
        int n=nums.size();
        for(int i=1;i<(1<<n);i++)
        {
            vector<int>res;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    res.push_back(nums[j]);
                }
            }
            int count=1;
            int flag=1;
            for(int k=1;k<res.size();k++)
            {
                if(res[k]>=res[k-1])
                {
                    count++;
                }
                else   
                {
                    flag=0;
                }
            }
            if(flag&&count>=2)
            {
                st.insert(res);
            }
        }
        for(auto it:st)
        {
            v.push_back(it);
        }
        return v;
    }
};