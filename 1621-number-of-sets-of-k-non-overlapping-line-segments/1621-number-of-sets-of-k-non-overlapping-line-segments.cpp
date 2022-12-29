class Solution {
public:
    int mod=1e9+7;
    long long storeOverlappingSubProblem[1001][1001][2];
    long long calculateAllLines(int n,int k,int start)
    {
        // we are find our answer
        if(k==0)
        {
            return 1;
        }
        // negative case
        if(n<=0)
        {
            return 0;
        }
        // if this problem all ready computated then return this value
        if(storeOverlappingSubProblem[n][k][start]!=-1)
        {
            return storeOverlappingSubProblem[n][k][start]%mod;
        }
        // not including this point
        long long ans=calculateAllLines(n-1,k,start);
        if(start)
        {
            // starting of the point
            ans+=calculateAllLines(n-1,k,0);
        }
        else if(start==0)
        {
            // ending of the point
            ans+=calculateAllLines(n,k-1,1);
        }
        return storeOverlappingSubProblem[n][k][start]= ans%mod;
    }
    int numberOfSets(int n, int k) {
        // initialize our matrix(storeOverLappingSubProblem) to -1
        
        memset(storeOverlappingSubProblem,-1,sizeof(storeOverlappingSubProblem));
        
        return (int)calculateAllLines(n,k,1)%mod;
    }
};