class Solution {
public:
    bool find(char ch)
    {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) 
    {
        int i=0;
        int n=words.size();
        vector<int>nums(n,0);
        for(auto &it:words)
        {
            if(find(it[0])==find(it.back())&&find(it[0]))
            {
                nums[i]=1;
            }
            i++;
        }
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        vector<int>ans;
        for(auto&it:q)
        {
            int l=it[0];
            int r=it[1];
            int value=(nums[r]);
            if(l-1>=0)
            {
                value-=nums[l-1];
            }
            ans.push_back(value);
        }
        return ans;
    }
};