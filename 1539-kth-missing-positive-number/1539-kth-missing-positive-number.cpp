class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        vector<int>v(10001,-1);
        for(int i=0;i<arr.size();i++)
        {
            v[arr[i]]=1;
        }
        int count=0;
        for(int i=1;i<10001;i++)
        {
            if(v[i]==-1)
            {
                count++;
            }
            if(count==k)
            {
                return i;
            }
            
        }
        return 0;
    }
};