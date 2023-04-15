class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>&mat) 
    {
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        for(int j=0;j<m;j++)
        {
            int max_val=0;
            for(int i=0;i<n;i++)
            {
                int x=mat[i][j];
                int count=0;
                if(x<0)
                {
                    count++;
                    x=abs(x);
                }
                count+=to_string(x).size();
                max_val=max(max_val,count);
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};