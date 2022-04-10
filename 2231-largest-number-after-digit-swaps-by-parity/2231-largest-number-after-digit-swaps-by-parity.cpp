class Solution {
public:
    int largestInteger(int num) 
    {
        int ans=num;
        string s=to_string(num);
        for(int i=0;i<s.size();i++)
        {
            int p=(s[i]-'0')%2;
            int max_index=i;
            int max_val=s[i]-'0';
            for(int j=i+1;j<s.size();j++)
            {
                if((s[j]-'0')%2==p&&max_val<(s[j]-'0'))
                {
                    max_val=(s[j]-'0');
                    max_index=j;
                }
            }
            swap(s[i],s[max_index]);
            ans=max(ans,stoi(s));
        }
        return ans;
    }
};