class Solution {
public:
    int in[300005],out[300005],prefix[300005],suffix[300005];
    int depth[300005];
    int time=1;
    void find(TreeNode*root,int d)
    {
        if(root==NULL)
        {
            return ;
        }
        depth[time]=d;
        in[root->val]=time++;
        find(root->left,d+1);
        find(root->right,d+1);
        out[root->val]=time++;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& q) 
    {
        find(root,0);
        for(int i=1;i<300005;i++)
        {
            prefix[i]=max(prefix[i-1],depth[i]);
        }
        for(int i=300003;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],depth[i]);
        }
        vector<int>ans;
        for(auto it:q)
        {
            int val=max(prefix[in[it]-1],suffix[out[it]+1]);
            ans.push_back(val);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int cnt, L[200005], R[200005], pre[200005], d[200005], suf[200005];
//     void dfs(TreeNode* x, int dep) {
//         L[x -> val] = ++ cnt;
//         d[cnt] = dep;
//         if (x -> left) dfs(x -> left, dep + 1);
//         if (x -> right) dfs(x -> right, dep + 1);
//         R[x -> val] = cnt;
//     }
//     vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
//         cnt = 0;
//         dfs(root, 0);
//         vector<int> v;
//         for (int i = 1; i <= cnt; i ++) pre[i] = max(pre[i - 1], d[i]);
//         suf[cnt + 1] = 0;
//         for (int i = cnt; i >= 1; i --) suf[i] = max(suf[i + 1], d[i]);
//         for (int i = 0; i < queries.size(); i ++) {
//             int x = queries[i];
//             v.push_back(max(pre[L[x] - 1], suf[R[x] + 1]));
//         }
//         return v;
//     }
// };