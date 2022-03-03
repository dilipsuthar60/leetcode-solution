class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int n=A.size();
        vector<int>v(n+1,0);
        int count=0;
        for(int i=2;i+1<v.size();i++)
        {
            if((A[i]-A[i-1])==(A[i-1]-A[i-2]))
            {
                v[i]=1+v[i-1];
                count+=v[i];
            }
        }
        return count;
    }
};