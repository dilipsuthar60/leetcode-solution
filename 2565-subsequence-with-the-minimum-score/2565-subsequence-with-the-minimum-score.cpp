class Solution {
public:
    bool find(string &s,string &t,int mid)
    {
        int n=s.size();
        int m=t.size();
        vector<int>left(m,n),right(m,-1);
        for(int i=0,j=0;j<m&&i<n;i++)
        {
            if(s[i]==t[j])
            {
                left[j]=i;
                j++;
            }
        }
        for(int i=n-1,j=m-1;j>=0&&i>=0;i--)
        {
            if(s[i]==t[j])
            {
                right[j]=i;
                j--;
            }
        }
        if(left[m-1]!=n)
        {
            return true;
        }
        if(right[mid]!=-1||left[m-mid-1]!=n)
        {
            return true;
        }
        for(int i=1;i+mid<m;i++)
        {
            if(left[i-1]<right[i+mid])
            {
                return true;
            }
        }
        return false;
    }
    int minimumScore(string s, string t) {
        int l=0;
        int r=t.size()-1;
        int ans=t.size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(s,t,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};