class Solution {
public:
    map<string,int>mp;
    string get_hash(int a,int b,int c,int d)
    {
        return to_string(a)+"##"+to_string(b)+"##"+to_string(c)+"##"+to_string(d);
    }
    int find(vector<vector<int>>&nums,int index,int prev_w,int prev_l,int prev_h)
    {
        if(index==nums.size())
        {
            return 0;
        }
        int inc=0;
        string hash_value=get_hash(index,prev_w,prev_l,prev_h);
        if(mp.find(hash_value)!=mp.end())
        {
            return mp[hash_value];
        }
        if(prev_w<=nums[index][0]&&prev_l<=nums[index][1]&&prev_h<=nums[index][2])
        {
            inc=nums[index][2]+find(nums,index+1,nums[index][0],nums[index][1],nums[index][2]);
        }
        int exc=find(nums,index+1,prev_w,prev_l,prev_h);
        return mp[hash_value]=max(inc,exc);
    }
    int maxHeight(vector<vector<int>>&nums)
    {
        for(auto &it:nums)
        {
            sort(it.begin(),it.end());
        }
        sort(nums.begin(),nums.end());
        return find(nums,0,INT_MIN,INT_MIN,INT_MIN);
    }
};