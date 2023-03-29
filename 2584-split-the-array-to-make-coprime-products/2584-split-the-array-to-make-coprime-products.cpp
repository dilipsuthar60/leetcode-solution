class Solution {
public:
    vector<int>find(int n)
    {
        vector<int>v;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                v.push_back(i);
                while(n%i==0)
                {
                    n=n/i;
                }
            }
        }
        if(n>1)
        {
            v.push_back(n);
        }
        return v;
    }
    int findValidSplit(vector<int>& nums) 
    {
        int n=nums.size();
        int max_val=*max_element(nums.begin(),nums.end());
        int hash[max_val+1];
        memset(hash,0,sizeof(hash));
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)
        {
            v[i]=find(nums[i]);
            for(auto &it:v[i])
            {
                hash[it]=i;
            }
        }
        int comman=0;
        for(int i=0;i<n-1;i++)
        {
            for(auto &it:v[i])
            {
                comman=max(comman,hash[it]);
            }
            if(comman==i)
            {
                return i;
            }
        }
        return -1;
    }
};