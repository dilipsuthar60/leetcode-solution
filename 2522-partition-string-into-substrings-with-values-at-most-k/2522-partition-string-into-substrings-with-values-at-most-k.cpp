class Solution {
public:
    int minimumPartition(string s, int k) {
        int n=s.size();
        long long sum=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]-'0')>k)
            {
                return -1;
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if((sum*10+(s[i]-'0'))<=k)
            {
                sum=sum*10+(s[i]-'0');
            }
            else
            {
                count++;
                sum=s[i]-'0';
            }
            // cout<<sum<<endl;
        }
        if(sum)
        {
            count++;
        }
        return count;
    }
};