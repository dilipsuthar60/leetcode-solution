class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int r=n*m-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int curr_val=mat[mid/m][mid%m];
            if(curr_val==target)
            {
                return true;
            }
            if(curr_val<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return false;
    }
};