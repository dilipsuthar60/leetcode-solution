class Solution {
public:
   
    int digArtifacts(int n, vector<vector<int>>& nums, vector<vector<int>>& dig) 
    {
        vector<vector<int>>mat(n,vector<int>(n,0));
        for(auto &it:dig)
        {
            mat[it[0]][it[1]]=1;
        }
        int count=0;
        for(auto &it:nums)
        {
            int f=1;
            for(int i=it[0];i<=it[2];i++)
            {
                for(int j=it[1];j<=it[3];j++)
                {
                    if(mat[i][j]==0)
                    {
                        f=0;
                    }
                }
            }
            if(f)
            {
                count++;
            }
        }
        return count;

    }
};