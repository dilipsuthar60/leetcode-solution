class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a)
    {
        int n=c.size();
        vector<long long>v;
        for(int i=0;i<n;i++)
        {
            v.push_back((c[i]-r[i]));
        }
        sort(v.begin(),v.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                count++;
            }
            else
            {
                int need=v[i];
                if(need<=a)
                {
                    a-=need;
                    count++;
                }
            }
        }
        return count;
    }
};