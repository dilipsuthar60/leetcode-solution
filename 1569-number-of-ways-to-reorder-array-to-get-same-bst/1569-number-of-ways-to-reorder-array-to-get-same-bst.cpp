class Solution {
public:
    int mod=1e9+7;
    vector<vector<long long>>table;
    void calc(int n)
    {
        table=vector<vector<long long>>(n);
        for(int i=0;i<n;i++)
        {
            vector<long long>v(i+1,1);
            for(int j=1;j<i;j++)
            {
                v[j]=(table[i-1][j]+table[i-1][j-1])%mod;
            }
            table[i]=v;
        }
    }
     long long find(vector<int>&nums)
    {
        if(nums.size()<3)
        {
            return 1;
        }
        vector<int>left,right;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums.front())
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
         long long lc=find(left);
         long long lr=find(right);
        return (((lc*lr)%mod)*table[nums.size()-1][right.size()])%mod;
    }
    int numOfWays(vector<int>& nums) 
    {
        calc(nums.size()+1);
        return (find(nums)-1+mod)%mod;
    }
};