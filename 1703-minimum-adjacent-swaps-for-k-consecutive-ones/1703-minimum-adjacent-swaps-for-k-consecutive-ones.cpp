class Solution {
public:
    int minMoves(vector<int>&arr, int k) 
    {
        vector<long long>nums,pos;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==1)
            {
                pos.push_back(i);
            }
        }
        int n=pos.size();
        nums=vector<long long>(n,0);
        nums[0]=pos[0];
        for(int i=1;i<n;i++)
        {
            nums[i]=nums[i-1]+pos[i];
        }
        long long ans=1e18;
        for(int i=0;i<n-k+1;i++)
        {
            long long mid=i+k/2;
            long long right_sum=nums[i+k-1]-nums[mid];
            long long left_sum=(mid==0?0:nums[mid-1])-((i==0)?0:nums[i-1]);
            long long total=right_sum-left_sum+(k%2==0?pos[mid]:0);
            ans=min(ans,total);
        }
        
        long long r=(k-1)/2;
        ans-=2*((r*(r+1))/2)+(((k%2)==0)?(r+1):0);
        return ans;
    }
};