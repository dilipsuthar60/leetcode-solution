class Solution {
public:
    int equalPairs(vector<vector<int>>&mat) {
        int n=mat.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=0;j<n;j++)
            {
                s+=to_string(mat[i][j])+"##";
            }
            mp[s]++;
        }
        int count=0;
        for(int j=0;j<n;j++)
        {
            string s="";
            for(int i=0;i<n;i++)
            {
                s+=to_string(mat[i][j])+"##";
            }
            count+=mp[s];
        }
        return count;
    }
};