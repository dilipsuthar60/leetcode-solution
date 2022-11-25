class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n=arr.size();
        stack<int>s;
        vector<int>left(n,-1),right(n,n);
        for(int i=0;i<n;i++)
        {
            while(s.size()&&arr[i]<=arr[s.top()])
            {
                s.pop();
            }
            if(s.size())
            {
                left[i]=s.top();
            }
            s.push(i);
        }
        s=stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()&&arr[i]<arr[s.top()])
            {
                s.pop();
            }
            if(s.size())
            {
                right[i]=s.top();
            }
            s.push(i);
        }
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            int left_len=(i-left[i]);
            int right_len=(right[i]-i);
            ans+=1ll*(arr[i])*(left_len*right_len);
            ans%=mod;
        }
        return (int)ans;
    }
};