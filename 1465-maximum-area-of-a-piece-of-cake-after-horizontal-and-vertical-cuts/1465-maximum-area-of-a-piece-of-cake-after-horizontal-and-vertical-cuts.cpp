class Solution {
public:
    vector<int>merge(vector<int>&left,vector<int>&right)
    {
        int i=0;
        int j=0;
        int n=left.size();
        int m=right.size();
        vector<int>ans(n+m);
        int k=0;
        while(i<n&&j<m)
        {
            if(left[i]<right[j])
            {
                ans[k++]=(left[i]);
                i++;
            }
            else
            {
                ans[k++]=(right[j]);
                j++;
            }
        }
        while(i<n)
        {
            ans[k++]=(left[i++]);
        }
        while(j<m)
        {
            ans[k++]=(right[j++]);
        }
        return ans;
    }
    vector<int> merge_sort(vector<int>&nums,int l,int r)
    {
        if(r==l)
        {
            return {nums[l]};
        }
        int mid=(l+r)/2;
       auto left=merge_sort(nums,l,mid);
       auto right=merge_sort(nums,mid+1,r);
       return merge(left,right);
    }
    int maxArea(int n, int m, vector<int>&h, vector<int>& v)
    {
        h.push_back(0);
        v.push_back(0);
        h.push_back(n);
        v.push_back(m);
        h=merge_sort(h,0,h.size()-1);
        v=merge_sort(v,0,v.size()-1);
        long long h_max=0;
        for(int i=1;i<h.size();i++)
        {
            h_max=max(h_max,0ll+h[i]-h[i-1]);
        }
        long long v_max=0;
        for(int i=1;i<v.size();i++)
        {
            v_max=max(v_max,0ll+v[i]-v[i-1]);
        }
        int mod=1e9+7;
        long long ans=((h_max%mod)*(v_max%mod))%mod;
        return (int)ans;
    }
};