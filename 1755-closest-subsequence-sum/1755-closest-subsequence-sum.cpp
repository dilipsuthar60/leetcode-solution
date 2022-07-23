class Solution {
public:
    using ll =long long int;
    vector<ll>find_subset(vector<ll>&nums)
    {
        ll n=nums.size();
        vector<ll>v;
        for(int i=0;i<(1<<n);i++)
        {
            ll sum=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    sum+=nums[j];
                }
            }
            v.push_back(sum);
        }
        return v;
    }
    int minAbsDifference(vector<int>& nums, int goal) 
    {
        
        vector<ll>left,right;
        ll N=nums.size();
       
        for(int i=0;i<N;i++)
        {
            if(i<N/2)
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
        vector<ll>left_sum=find_subset(left);
        vector<ll>right_sum=find_subset(right);
        ll ans=1e9;
        sort(left_sum.begin(),left_sum.end());
        sort(right_sum.begin(),right_sum.end());
        for(auto curr:left_sum)
        {
            int index=lower_bound(right_sum.begin(),right_sum.end(),goal-curr)-right_sum.begin();

            if(index>=0&&index<right_sum.size())
            {
                ans=min(ans,abs(goal-(curr+right_sum[index])));
            }
            index--;
            if(index>=0)
            {
                ans=min(ans,abs(goal-(curr+right_sum[index])));
            }
           
        }
        return (int)ans;
    }
};