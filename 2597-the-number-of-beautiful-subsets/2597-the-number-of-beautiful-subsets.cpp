class Solution {
public:
     int mp[2100];
    int find(vector<int>&nums,int index,int k)
    {
        if(index>=nums.size())
        {
            return 1;
        }
        int count=find(nums,index+1,k);
        if(mp[nums[index]-k+1000]==0)
        {
            mp[nums[index]+1000]++;
            count+=find(nums,index+1,k);
            mp[nums[index]+1000]--;
        }
        return count;
    }
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        memset(mp,0,sizeof(mp));
        sort(nums.begin(),nums.end());
        return find(nums,0,k)-1;
        // int count=0;
        // int n=nums.size();
        // for(int i=1;i<(1<<n);i++)
        // {
        //     int f=1;
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i&(1<<j))
        //         {
        //             if(mp[nums[j]-k+1000]==i)
        //             {
        //                 f=0;
        //                 break;
        //             }
        //             mp[nums[j]+1000]=i;
        //         }
        //     }
        //     if(f)
        //     {
        //         count++;
        //     }
        // }
        // return count;
    }
};