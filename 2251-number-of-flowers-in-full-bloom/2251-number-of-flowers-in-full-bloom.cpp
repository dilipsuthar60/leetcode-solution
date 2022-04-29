class Solution {
public:
    vector<int>merge(vector<int>&left,vector<int>&right)
    {
        vector<int>sorted_array(left.size()+right.size());
        int i=0;
        int j=0;
        int k=0;
        while(i<left.size()&&j<right.size())
        {
            if(left[i]<right[j])
            {
                sorted_array[k++]=(left[i++]);
            }
            else
            {
                sorted_array[k++]=(right[j++]);
            }
        }
        while(i<left.size()) sorted_array[k++]=(left[i++]);
        while(j<right.size()) sorted_array[k++]=(right[j++]);
        return sorted_array;
    }
    vector<int> sort(vector<int>&nums,int l,int r)
    {
        if(l==r)
        {
            return {nums[l]};
        }
        int mid=(l+r)/2;
        vector<int>left=sort(nums,l,mid);
        vector<int>right=sort(nums,mid+1,r);
        return merge(left,right);
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& nums, vector<int>& p) 
    {
        vector<int>start,end;
        for(auto &it:nums)
        {
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
        
        start=sort(start,0,start.size()-1);
        end=sort(end,0,end.size()-1);
        vector<int>ans;
        for(auto &it:p)
        {
            int val=it;
            int l=upper_bound(start.begin(),start.end(),val)-start.begin();
            int r=lower_bound(end.begin(),end.end(),val)-end.begin();
            ans.push_back(l-r);
        }
        return ans;
    }
};