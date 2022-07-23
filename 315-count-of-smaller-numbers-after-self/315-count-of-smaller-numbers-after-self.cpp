class Solution {
public:
    const int mx=1e5+10;
    int bit[100005+10];
    void update(int i,int val)
    {
        while(i<mx)
        {
            bit[i]+=val;
            i=i+(i&-i);
        }
    }
    int find(int i)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i=i-(i&-i);
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>temp=nums;
        // bit=vector<int>(mx,0);
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++)
        {
            nums[i]=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin()+1;
        }
        vector<int>v(n,0);
        for(int i=n-1;i>=0;i--)
        {
            v[i]=find(nums[i]-1);
            update(nums[i],1);
        }
        return v;
    }
};