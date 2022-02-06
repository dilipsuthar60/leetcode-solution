class Solution {
public:
    void find(string s,vector<int>&nums)
    {
        if(s[0]=='1')
        {
            nums[0]=1;
        }
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            nums[i]=(s[i]=='1')?min(nums[i-1]+2,i+1):nums[i-1];
        }
    }
    int minimumTime(string s) 
    {
        int n=s.size();
        if(n==1&&s[0]=='1')
        {
            return 1;
        }
        vector<int>left(n,0),right(n,0);
        find(s,left);
        reverse(s.begin(),s.end());
        find(s,right);
        reverse(right.begin(),right.end());
        // for(int i=0;i<n;i++)
        // {
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<right[i]<<" ";
        // }
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            ans=min(ans,left[i]+right[i+1]);
        }
        return ans==INT_MAX?0:ans;
    }
};