class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) 
    {
        int n=nums.size();
        vector<int>left(n,-1),right(n,n);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        set<int>s;
        sort(v.begin(),v.end());
        for(auto &[val,i]:v)
        {
            auto it=s.lower_bound(i);
            if(it!=s.end())
            {
                right[i]=*it;
            }
            if(it!=s.begin())
            {
                it--;
                left[i]=*it;
            }
            s.insert(i);
        }
        for(int i=0;i<n;i++)
        {
            // cout<<left[i]<<"  "<<right[i]<<endl;
            int len=(right[i]-left[i]-1);
            if(1ll*nums[i]*len>threshold)
            {
                return len;
            }
        }
        return -1;
    }
};