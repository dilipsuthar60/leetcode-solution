class Solution {
public:
    long long find(long long n,int len)
    {
        long long pal=n;
        if(len%2)
        {
            n/=10;
        }
        while(n)
        {
            pal=pal*10+n%10;
            n=n/10; 
        }
        return pal;
    }
    vector<long long> kthPalindrome(vector<int>& q, int len) 
    {
        vector<long long>ans(q.size(),-1);
        long long start=pow(10,(len-1)/2);
        long long end=pow(10,(len+1)/2);
        int index=-1;
        for(auto &it:q)
        {
            it--;
            index++;
            if((start+it)<end)
            {
                ans[index]=find(start+it,len);
            }
        }
        return ans;
    }
};