class Solution {
public:
    int N=1e5+10;
    vector<int>bit;
    void update(int i,int val)
    {
        while(i<N)
        {
            bit[i]=max(bit[i],val);
            i=i+(i&-i);
        }
    }
    int find(int i)
    {
        int ans=0;
        while(i>0)
        {
            ans=max(bit[i],ans);
            i=i-(i&-i);
        }
        return ans;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>&nums)
    {
        bit=vector<int>(N,0);
        int n=nums.size();
       vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++)
        {
            nums[i]=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin()+1;
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int x=find(nums[i]);
            ans[i]=x+1;
            update(nums[i],x+1);
        }
        return ans;
    }
};