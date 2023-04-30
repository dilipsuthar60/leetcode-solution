class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
         unordered_map<int,pair<int,int>>mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0;i<arr.size();i++)
        {
            auto temp=mp[arr[i]];
            row[temp.first]++;
            col[temp.second]++;
            if(row[temp.first]==m||col[temp.second]==n)
            {
                return i;
            }
        }
        return -1;
    }
};