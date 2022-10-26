class TreeAncestor {
public:
    int dp[20][100000];
    TreeAncestor(int n, vector<int>& parent) 
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=parent[i];
        }
        for(int i=1;i<20;i++)
        {
            for(int node=0;node<n;node++)
            {
                if(dp[i-1][node]!=-1)
                {
                    dp[i][node]=dp[i-1][dp[i-1][node]];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) 
    {
        for(int i=0;i<20;i++)
        {
            if(k&(1<<i))
            {
                node=dp[i][node];
                if(node==-1)
                {
                    break;
                }
            }
        }
        return node;
    }
};

/**
 for(int i = 0; i < parent.size(); i++){
            P[0][i] = parent[i];
        }
        
        // 2^i
        for(int i = 1; i < 20; i++){
            for(int node = 0; node < parent.size(); node ++){
                int nodep = P[i-1][node];
                if(nodep != -1) P[i][node] = P[i-1][nodep];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; i++){
            if(k & (1 << i)){
                node = P[i][node];
                if(node == -1) return -1;
            }
        }

        return node;
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */